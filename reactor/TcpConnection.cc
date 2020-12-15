#include"TcpConnection.h"

#include"Channel.h"
#include "EventLoop.h"
#include "Socket.h"
#include"SocketsOps.h"
#include<boost/bind.hpp>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
template<typename To, typename From>
inline To implicit_cast(From const &f) {
    return f;
}
TcpConnection::TcpConnection(EventLoop* loop,const std::string& nameArg,int sockfd,const InetAddress& localAddr,const InetAddress& peerAddr):
loop_(loop),
name_(nameArg),
state_(kConnecting),
socket_(new Socket(sockfd)),
channel_(new Channel(loop, sockfd)),
localAddr_(localAddr),
peerAddr_(peerAddr)
{
    channel_->setReadCallback(
      boost::bind(&TcpConnection::handleRead, this, _1));
    channel_->setWriteCallback(
      boost::bind(&TcpConnection::handleWrite, this));
    channel_->setCloseCallback(
      boost::bind(&TcpConnection::handleClose, this));
    channel_->setErrorCallback(
      boost::bind(&TcpConnection::handleError, this));
}
TcpConnection::~TcpConnection()
{

}
void TcpConnection::shutdown()
{
    if(state_ == kConnected){
        setState(kDisconnecting);
        loop_->runInLoop(boost::bind(&TcpConnection::shutdownInloop,this));
    }
}
void TcpConnection::shutdownInloop()
{
    loop_->assertInLoopThread();
    if(!channel_->isWriting()){
        socket_->shutdownWrite();
    }
}
void TcpConnection::setTcpNoDelay(bool on)
{
  socket_->setTcpNoDelay(on);
}
void TcpConnection::connectEstablished()
{
    loop_->assertInLoopThread();
    assert(state_ == kConnecting);
    setState(kConnected);
    channel_->enableReading();

    connectionCallback_(shared_from_this());

}

void TcpConnection::send(const std::string& message)
{
    if(state_ == kConnected){
        if(loop_->isInLoopThread()){
            sendInloop(message);
        }
        else{
            loop_->runInLoop(boost::bind(&TcpConnection::sendInloop,this,message));
        }
    }
}
void TcpConnection::sendInloop(const std::string& message)
{
    loop_->assertInLoopThread();
    ssize_t nwrote = 0;
    if(!channel_->isWriting() && outputBuffer_.readableBytes() == 0){
        nwrote = ::write(channel_->fd(),message.data(),message.size());
        if(nwrote>=0){

        }
        else{
            nwrote = 0;
            if(errno != EWOULDBLOCK){
                perror("TcpConnection::sendInloop");
            }
        }
    }
    assert(nwrote>=0);
    if(implicit_cast<size_t>(nwrote) < message.size()){
        outputBuffer_.append(message.data()+nwrote,message.size()-nwrote);
        if(!channel_->isWriting()){
            channel_->enableWriting();
        }
    }
}
void TcpConnection::connectDestroyed()
{
    loop_->assertInLoopThread();
    assert(state_ == kConnected || state_ == kDisconnecting);
    setState(kDisconnected);
    channel_->disableAll();
    connectionCallback_(shared_from_this());
    loop_->removeChannel(get_pointer(channel_));
}
void TcpConnection::handleRead(Timestamp receiveTime)
{
    //char buf[65536];
    //ssize_t n = ::read(channel_->fd(),buf, sizeof(buf));
    int saveErrno = 0;
    ssize_t n = inputBuffer_.readFd(channel_->fd(),&saveErrno);
    if(n > 0){
        messageCallback_(shared_from_this(),&inputBuffer_,receiveTime);
    }
    else if(n==0){
        handleClose();
    }
    else{
        errno = saveErrno;
        handleError();
    }
}
void TcpConnection::handleWrite()
{
    loop_->assertInLoopThread();
    if(channel_->isWriting()){
        ssize_t n = ::write(channel_->fd(),outputBuffer_.peek(),outputBuffer_.readableBytes());
        if(n>0){
            outputBuffer_.retrieve(n);
            if(outputBuffer_.readableBytes()==0){
                channel_->disableWriting();
                if(state_ == kDisconnecting){
                    shutdownInloop();
                }
            }
        }
    }
}
void TcpConnection::handleClose()
{
    loop_->assertInLoopThread();
    assert(state_ == kConnected||state_ == kDisconnecting);
    channel_->disableAll();
    closeCallback_(shared_from_this());
}
void TcpConnection::handleError()
{
    int err = sockets::getSocketError(channel_->fd());
    perror("TcpConnection::handleError");
}