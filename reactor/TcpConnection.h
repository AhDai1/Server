// excerpts from http://code.google.com/p/muduo/
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
// Author: Shuo Chen (chenshuo at chenshuo dot com)

#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include "Callbacks.h"
#include "InetAddress.h"
#include "Buffer.h"

#include <boost/any.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include"StringPiece.h"


class Channel;
class EventLoop;
class Socket;

///
/// TCP connection, for both client and server usage.
///
class TcpConnection : boost::noncopyable,
                      public boost::enable_shared_from_this<TcpConnection>
{
public:
  /// Constructs a TcpConnection with a connected sockfd
  ///
  /// User should not create this object.
  TcpConnection(EventLoop* loop,
                const std::string& name,
                int sockfd,
                const InetAddress& localAddr,
                const InetAddress& peerAddr);
  ~TcpConnection();

  EventLoop* getLoop() const { return loop_; }
  const std::string& name() const { return name_; }
  const InetAddress& localAddress() { return localAddr_; }
  const InetAddress& peerAddress() { return peerAddr_; }
  bool connected() const { return state_ == kConnected; }


  void shutdown();

void setTcpNoDelay(bool on);
  void setContext(const boost::any &context)
  {context_ = context;}

  void setConnectionCallback(const ConnectionCallback& cb)
  { connectionCallback_ = cb; }

  void setMessageCallback(const MessageCallback& cb)
  { messageCallback_ = cb; }

  void setWriteCompleteCallback(const WriteCompleteCallback& cb)
  { writeCompleteCallback_ = cb; }
    void setCloseCallback(const CloseCallback& cb )
    { closeCallback_ = cb;}
  void setHighWaterMarkCallback(const HighWaterMarkCallback& cb, size_t highWaterMark)
  { highWaterMarkCallback_ = cb; highWaterMark_ = highWaterMark; }
  boost::any* getMutableContext()
  { return &context_; }
  /// Internal use only.

  // called when TcpServer accepts a new connection
  void connectEstablished();   // should be called only once
    void connectDestroyed();
     void send(const void* message, int len);
  void send(const StringPiece& message);
  // void send(Buffer&& message); // C++11
  void send(Buffer* message);  // this one will swap data
  // void send(const void* message,size_t len);
  // void send(const std::string& message);
  // void send(Buffer* buf);
 private:
  enum StateE { kConnecting, kConnected,kDisconnecting,kDisconnected };

  void setState(StateE s) { state_ = s; }
  void handleRead(Timestamp receiveTime);
  void handleWrite();
  void handleClose();
  void handleError();

 
  //void sendInloop(const std::string& message);
  void sendInLoop(const StringPiece& message);
  void sendInLoop(const void* data, size_t len);
  void shutdownInloop();

  EventLoop* loop_;
  std::string name_;
  StateE state_;  // FIXME: use atomic variable
  // we don't expose those classes to client.
  boost::scoped_ptr<Socket> socket_;
  boost::scoped_ptr<Channel> channel_;
  InetAddress localAddr_;
  InetAddress peerAddr_;
  ConnectionCallback connectionCallback_;
  MessageCallback messageCallback_;
  CloseCallback closeCallback_;
  WriteCompleteCallback writeCompleteCallback_;
  HighWaterMarkCallback highWaterMarkCallback_;

  size_t highWaterMark_;
  Buffer inputBuffer_;
  Buffer outputBuffer_;
  boost::any context_;
};

typedef boost::shared_ptr<TcpConnection> TcpConnectionPtr;



#endif  // TCPCONNECTION_H
