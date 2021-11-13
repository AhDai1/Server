#include "TcpServer.h"

#include"Acceptor.h"
#include "EventLoop.h"
#include "SocketsOps.h"
#include "EventLoopThreadPool.h"

#include<boost/bind.hpp>
#include<stdio.h>
#include<assert.h>

TcpServer::TcpServer(EventLoop* loop,const InetAddress& listenAddr):
loop_(loop),//TcpServer所在线程的事件循环
name_(listenAddr.toHostPort()),//服务器名字
acceptor_(new Acceptor(loop,listenAddr)),//负责监听客户端连接
threadPool_(new EventLoopThreadPool(loop)),
started_(false),
nextConnId_(1)//TcpConnection ID逐个加一
{
    //设置回调函数，Acceptor接受客户请求然后调用这里的回调函数，用于创建TcpConnection
    acceptor_->setNewConnectionCallback(boost::bind(&TcpServer::newConnection,this,_1,_2));
}
TcpServer::~TcpServer()
{

}
void TcpServer::setThreadNum(int numThreads)
{
  assert(0 <= numThreads);
  threadPool_->setThreadNum(numThreads);
}
void TcpServer::start()
{
    if(!started_){
        started_=true;
        threadPool_->start();
    }
    if(!acceptor_->listenning()){
        loop_->runInLoop(boost::bind(&Acceptor::listen,get_pointer(acceptor_)));
    }
}
void TcpServer::newConnection(int sockfd, const InetAddress& peerAddr)
{
    loop_->assertInLoopThread();
    char buf[32];
    snprintf(buf,sizeof(buf), "#%d", nextConnId_);
    ++nextConnId_;
    std::string connName = name_ + buf;
    InetAddress localAddr(sockets::getLocalAddr(sockfd));//根据socket fd获取tcp连接在本地的地址、端口
    EventLoop* ioLoop = threadPool_->getNextLoop();
    //创建一个新的TcpConnection代表一个Tcp连接
    TcpConnectionPtr conn(new TcpConnection(ioLoop,connName,sockfd,localAddr,peerAddr));
    connections_[connName] = conn;//添加到所有tcp连接的map中
    //设置一系列回调函数
    conn->setConnectionCallback(connectionCallback_);
    conn->setMessageCallback(messageCallback_);
    conn->setCloseCallback(boost::bind(&TcpServer::removeConnection,this,_1));
    conn->setWriteCompleteCallback(writeCompleteCallback_);
    ioLoop->runInLoop(boost::bind(&TcpConnection::connectEstablished, conn));
}

void TcpServer::removeConnection(const TcpConnectionPtr& conn)
{
    loop_->runInLoop(boost::bind(&TcpServer::removeConnectionInLoop, this, conn));
}
void TcpServer::removeConnectionInLoop(const TcpConnectionPtr& conn)
{
  loop_->assertInLoopThread();
  size_t n = connections_.erase(conn->name());
  assert(n == 1); (void)n;
  EventLoop* ioLoop = conn->getLoop();
  ////将TcpConnection的生命期长到调用connectDestroyed的时候
  ioLoop->queueInLoop(
      boost::bind(&TcpConnection::connectDestroyed, conn));
}
