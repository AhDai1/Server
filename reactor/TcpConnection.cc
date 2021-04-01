#include"TcpConnection.h"

#include"Channel.h"
#include "EventLoop.h"
#include "Socket.h"
#include"SocketsOps.h"
#include<boost/bind.hpp>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

TcpConnection::TcpConnection(EventLoop* loop,const std::string& nameArg,int sockfd,const InetAddress& localAddr,const InetAddress& peerAddr):
loop_(loop),
name_(nameArg),
state_(kConnecting),
socket_(new Socket(sockfd)),
channel_(new Channel(loop, sockfd)),
localAddr_(localAddr),
peerAddr_(peerAddr),
highWaterMark_(64*1024*1024)
{
    channel_->setReadCallback(
      boost::bind(&TcpConnection::handleRead, this, _1));
    channel_->setWriteCallback(
      boost::bind(&TcpConnection::handleWrite, this));
    channel_->setCloseCallback(
      boost::bind(&TcpConnection::handleClose, this));
    channel_->setErrorCallback(
      boost::bind(&TcpConnection::handleError, this));
      socket_->setKeepAlive(true);
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

// void TcpConnection::send(const std::string& message)
// {
//     if(state_ == kConnected){
//         if(loop_->isInLoopThread()){
//             sendInloop(message);
//         }
//         else{
//             loop_->runInLoop(boost::bind(&TcpConnection::sendInloop,this,message));
//         }
//     }
// }

// void TcpConnection::sendInloop(const std::string& message)
// {
//     loop_->assertInLoopThread();
//     ssize_t nwrote = 0;
//     if(!channel_->isWriting() && outputBuffer_.readableBytes() == 0){
//         nwrote = ::write(channel_->fd(),message.data(),message.size());
//         if(nwrote>=0){
//             if (implicit_cast<size_t>(nwrote) < message.size()) {
            
//             }else if (writeCompleteCallback_) {
//             loop_->queueInLoop(boost::bind(writeCompleteCallback_, shared_from_this()));
//       }
//         }
//         else{
//             nwrote = 0;
//             if(errno != EWOULDBLOCK){
//                 perror("TcpConnection::sendInloop");
//             }
//         }
//     }
//     assert(nwrote>=0);
//     if(implicit_cast<size_t>(nwrote) < message.size()){
//         outputBuffer_.append(message.data()+nwrote,message.size()-nwrote);
//         if(!channel_->isWriting()){
//             channel_->enableWriting();
//         }
//     }
// }


void TcpConnection::send(const void* data, int len)
{
  send(StringPiece(static_cast<const char*>(data), len));
}

void TcpConnection::send(const StringPiece& message)
{
  if (state_ == kConnected)
  {
    if (loop_->isInLoopThread())
    {
      sendInLoop(message);
    }
    else
    {
      void (TcpConnection::*fp)(const StringPiece& message) = &TcpConnection::sendInLoop;
      loop_->runInLoop(
          std::bind(fp,
                    this,     // FIXME
                    message.as_string()));
                    //std::forward<string>(message)));
    }
  }
}

// FIXME efficiency!!!
void TcpConnection::send(Buffer* buf)
{
  if (state_ == kConnected)
  {
    if (loop_->isInLoopThread())
    {
      sendInLoop(buf->peek(), buf->readableBytes());
      buf->retrieveAll();
    }
    else
    {
      void (TcpConnection::*fp)(const StringPiece& message) = &TcpConnection::sendInLoop;
      loop_->runInLoop(
          std::bind(fp,
                    this,     // FIXME
                    buf->retrieveAllAsString()));
                    //std::forward<string>(message)));
    }
  }
}

void TcpConnection::sendInLoop(const StringPiece& message)
{
  sendInLoop(message.data(), message.size());
}

void TcpConnection::sendInLoop(const void* data, size_t len)
{
  loop_->assertInLoopThread();
  ssize_t nwrote = 0;
  size_t remaining = len;
  bool faultError = false;
  if (state_ == kDisconnected)
  {
  
    return;
  }
  // if no thing in output queue, try writing directly
  if (!channel_->isWriting() && outputBuffer_.readableBytes() == 0)
  {
    nwrote = sockets::write(channel_->fd(), data, len);
    if (nwrote >= 0)
    {
      remaining = len - nwrote;
      if (remaining == 0 && writeCompleteCallback_)
      {
        loop_->queueInLoop(std::bind(writeCompleteCallback_, shared_from_this()));
      }
    }
    else // nwrote < 0
    {
      nwrote = 0;
      if (errno != EWOULDBLOCK)
      {
        
        if (errno == EPIPE || errno == ECONNRESET) // FIXME: any others?
        {
          faultError = true;
        }
      }
    }
  }

  assert(remaining <= len);
  if (!faultError && remaining > 0)
  {
    size_t oldLen = outputBuffer_.readableBytes();
    if (oldLen + remaining >= highWaterMark_
        && oldLen < highWaterMark_
        && highWaterMarkCallback_)
    {
      loop_->queueInLoop(std::bind(highWaterMarkCallback_, shared_from_this(), oldLen + remaining));
    }
    outputBuffer_.append(static_cast<const char*>(data)+nwrote, remaining);
    if (!channel_->isWriting())
    {
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
                if (writeCompleteCallback_) {
                     loop_->queueInLoop(boost::bind(writeCompleteCallback_, shared_from_this()));
                }
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

