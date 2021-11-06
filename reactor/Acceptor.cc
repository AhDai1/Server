#include"Acceptor.h"
#include "EventLoop.h"
#include "InetAddress.h"
#include"SocketsOps.h"
#include"Channel.h"
#include<boost/bind.hpp>
#include<assert.h>

Acceptor::Acceptor(EventLoop* loop,const InetAddress& listenAddr):
loop_(loop),
acceptSocket_(sockets::createNonblockingOrDie()),//创建非阻塞socket
acceptChannel_(loop,acceptSocket_.fd()),//将socket fd放入Channel中管理
listenning_(false)
{
    acceptSocket_.setReuseAddr(true);//设置端口复用
    acceptSocket_.bindAddress(listenAddr);//绑定地址信息
    acceptChannel_.setReadCallback(boost::bind(&Acceptor::handleRead,this));//设置读事件的回调函数
}

void Acceptor::listen()
{
    loop_->assertInLoopThread();
    listenning_=true;
    acceptSocket_.listen();
    acceptChannel_.enableReading();//将listening socket fd 注册进pollfds
}

void Acceptor::handleRead()//一旦socket监听到连接，就立刻调用回调函数
{
    loop_->assertInLoopThread();
    InetAddress peerAddr(0);//对端的地址信息
    int connfd = acceptSocket_.accept(&peerAddr);
    if(connfd>=0){
        if(newConnectionCallback_){
            newConnectionCallback_(connfd,peerAddr);//调用回调把信息传给TcpServer
        }
        else{
            sockets::close(connfd);
        }
    }
}