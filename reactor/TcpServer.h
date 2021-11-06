#ifndef TCPSERVER_H
#define TCPSERVER_H

#include"TcpConnection.h"
#include"Callbacks.h"

#include <map>
#include<boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>

class Acceptor;
class EventLoop;
class EventLoopThreadPool;

class TcpServer:boost::noncopyable
{
public:
    TcpServer(EventLoop* loop,const InetAddress& listenAddr);
    ~TcpServer();
    void setThreadNum(int numThreads);
    void start();
    void setConnectionCallback(const ConnectionCallback& cb)
    {connectionCallback_ = cb;}
    void setMessageCallback(const MessageCallback& cb)
    {messageCallback_ = cb;}
    void setWriteCompleteCallback(const WriteCompleteCallback& cb)
  { writeCompleteCallback_ = cb; }
private:
    void newConnection(int sockfd,const InetAddress& peerAddr);
    void removeConnection(const TcpConnectionPtr& conn);
    void removeConnectionInLoop(const TcpConnectionPtr& conn);
    typedef std::map<std::string, TcpConnectionPtr> ConnectionMap;//连接与名字的映射

    EventLoop* loop_;//本TcpServer所在的事件循环
    const std::string name_;
    boost::scoped_ptr<Acceptor> acceptor_;//不可转交的Acceptor
    boost::scoped_ptr<EventLoopThreadPool> threadPool_;
    ConnectionCallback connectionCallback_;
    MessageCallback messageCallback_;
    WriteCompleteCallback writeCompleteCallback_;
    bool started_;
    int nextConnId_;
    ConnectionMap connections_;
};

#endif // !TCPSERVER_H
