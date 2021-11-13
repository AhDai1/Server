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
highWaterMark_(64*1024*1024)//设置缓冲区上限
{
    channel_->setReadCallback(//读事件
      boost::bind(&TcpConnection::handleRead, this, _1));
    channel_->setWriteCallback(//写事件
      boost::bind(&TcpConnection::handleWrite, this));
    channel_->setCloseCallback(//关闭事件
      boost::bind(&TcpConnection::handleClose, this));
    channel_->setErrorCallback(//错误事件
      boost::bind(&TcpConnection::handleError, this));
      socket_->setKeepAlive(true);//开启Tcp/Ip层心跳包检测
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
    loop_->assertInLoopThread();//断言处于loop线程
    assert(state_ == kConnecting);//断言处于未连接
    setState(kConnected);//设置为已连接
    channel_->enableReading();//关注可读事件，加入到Poller中关注

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
                    this,     
                    message.as_string()));
                  
    }
  }
}

// FIXME efficiency!!!
void TcpConnection::send(Buffer* buf)
{
  if (state_ == kConnected)
  {
    if (loop_->isInLoopThread())//如果线程是所属loop线程
    {
      sendInLoop(buf->peek(), buf->readableBytes());
      buf->retrieveAll();//对缓冲区复位
    }
    else//如果不是所属loop线程，则调用runInLoop
    {
      void (TcpConnection::*fp)(const StringPiece& message) = &TcpConnection::sendInLoop;
      loop_->runInLoop(
          std::bind(fp, this, buf->retrieveAllAsString()));
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
  //如果没有关注写事件，并且发送缓冲区没有数据，可以尝试直接write
  if (!channel_->isWriting() && outputBuffer_.readableBytes() == 0)
  {
    nwrote = sockets::write(channel_->fd(), data, len);
    if (nwrote >= 0)
    {
      remaining = len - nwrote;
      //如果数据全部发送完毕（拷贝到内核缓冲区）并且回调函数存在
      if (remaining == 0 && writeCompleteCallback_)
      {
        loop_->queueInLoop(std::bind(writeCompleteCallback_, shared_from_this()));//交给IO线程执行
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
  if (!faultError && remaining > 0)//如果没有一次性将数据写到内核缓冲区，则将数据写到outputBuffer中
  {
    size_t oldLen = outputBuffer_.readableBytes();
    if (oldLen + remaining >= highWaterMark_
        && oldLen < highWaterMark_
        && highWaterMarkCallback_)
    {
      loop_->queueInLoop(std::bind(highWaterMarkCallback_, shared_from_this(), oldLen + remaining));
    }
    outputBuffer_.append(static_cast<const char*>(data)+nwrote, remaining);
    if (!channel_->isWriting())//如果没有关注writable事件，那么设置writable事件
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
    connectionCallback_(shared_from_this());//回调用户函数，通知连接已断开
    loop_->removeChannel(get_pointer(channel_));
}

void TcpConnection::handleRead(Timestamp receiveTime)
{
    //char buf[65536];
    //ssize_t n = ::read(channel_->fd(),buf, sizeof(buf));
    int saveErrno = 0;
    //将sockfd数据从内核读取到inputBuffer的缓冲区
    ssize_t n = inputBuffer_.readFd(channel_->fd(),&saveErrno);
    if(n > 0){
        messageCallback_(shared_from_this(),&inputBuffer_,receiveTime);//将数据传到上层
    }
    else if(n==0){
        handleClose();//处理关闭连接事件
    }
    else{
        errno = saveErrno;
        handleError();//处理错误事件
    }
}
void TcpConnection::handleWrite()
{
    loop_->assertInLoopThread();
    if(channel_->isWriting()){//如果关注writable事件
        //如果内核缓冲区有空间，直接调用write
        ssize_t n = ::write(channel_->fd(),outputBuffer_.peek(),outputBuffer_.readableBytes());
        if(n>0){
            outputBuffer_.retrieve(n);//写了n个字节就回收应用层的缓冲空间
            if(outputBuffer_.readableBytes()==0){
                channel_->disableWriting();//停止关注
                if (writeCompleteCallback_) {//应用层没有数据了
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
    channel_->disableAll();//解除所有关注事件
    closeCallback_(shared_from_this());//回调TcpServer::removeConnection
}
void TcpConnection::handleError()
{
    int err = sockets::getSocketError(channel_->fd());
    perror("TcpConnection::handleError");
}

