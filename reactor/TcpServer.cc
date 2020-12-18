#include "TcpServer.h"

#include"Acceptor.h"
#include "EventLoop.h"
#include "SocketsOps.h"
//#include "EventLoopThreadPool.h"

#include<boost/bind.hpp>
#include<stdio.h>

TcpServer::TcpServer(EventLoop* loop,const InetAddress& listenAddr):
loop_(loop),
name_(listenAddr.toHostPort()),
acceptor_(new Acceptor(loop,listenAddr)),
//threadPool_(new EventLoopThreadPool(loop)),
started_(false),
nextConnId_(1)
{
    acceptor_->setNewConnectionCallback(boost::bind(&TcpServer::newConnection,this,_1,_2));
}
TcpServer::~TcpServer()
{

}
// void TcpServer::setThreadNum(int numThreads)
// {
//   assert(0 <= numThreads);
//   threadPool_->setThreadNum(numThreads);
// }
void TcpServer::start()
{
    if(!started_){
        started_=true;
        //threadPool_->start();
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
    ++nextConnId_;//***************************************************8
    std::string connName = name_ + buf;
    InetAddress localAddr(sockets::getLocalAddr(sockfd));
    //EventLoop* ioLoop = threadPool_->getNextLoop();
    TcpConnectionPtr conn(new TcpConnection(loop_,connName,sockfd,localAddr,peerAddr));
    connections_[connName] = conn;
    conn->setConnectionCallback(connectionCallback_);
    conn->setMessageCallback(messageCallback_);
    conn->setCloseCallback(boost::bind(&TcpServer::removeConnection,this,_1));
    conn->setWriteCompleteCallback(writeCompleteCallback_);
    //ioLoop->runInLoop(boost::bind(&TcpConnection::connectEstablished, conn));
    conn->connectEstablished();
}

// void TcpServer::removeConnection(const TcpConnectionPtr& conn)
// {
//     loop_->runInLoop(boost::bind(&TcpServer::removeConnectionInLoop, this, conn));???????//
// }
// void TcpServer::removeConnectionInLoop(const TcpConnectionPtr& conn)
// {
//   loop_->assertInLoopThread();
//   size_t n = connections_.erase(conn->name());
//   assert(n == 1); (void)n;
//   EventLoop* ioLoop = conn->getLoop();
//   ioLoop->queueInLoop(
//       boost::bind(&TcpConnection::connectDestroyed, conn));
// }
void TcpServer::removeConnection(const TcpConnectionPtr& conn)
{
  loop_->assertInLoopThread();
  size_t n = connections_.erase(conn->name());
  assert(n == 1); (void)n;
  loop_->queueInLoop(
      boost::bind(&TcpConnection::connectDestroyed, conn));
}