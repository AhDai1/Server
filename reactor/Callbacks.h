// excerpts from http://code.google.com/p/muduo/
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
// Author: Shuo Chen (chenshuo at chenshuo dot com)

#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>

#include "Timestamp.h"
#include"Buffer.h"
class HttpRequest;
class HttpResponse;


// All client visible callbacks go here.
class TcpConnection;
typedef boost::shared_ptr<TcpConnection> TcpConnectionPtr;

typedef boost::function<void()> TimerCallback;


typedef boost::function<void (const TcpConnectionPtr&)> ConnectionCallback;
typedef boost::function<void (const TcpConnectionPtr&,Buffer *buf, Timestamp)> MessageCallback;
typedef boost::function<void (const TcpConnectionPtr&)> CloseCallback;
typedef boost::function<void (const TcpConnectionPtr&)> WriteCompleteCallback;
typedef boost::function<void (const HttpRequest&,HttpResponse*)> HttpCallback;
typedef std::function<void (const TcpConnectionPtr&, size_t)> HighWaterMarkCallback;



#endif  // CALLBACKS_H
