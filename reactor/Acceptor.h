#ifndef ACCEPTOR_H
# define ACCERTOR_H

#include<boost/function.hpp>
#include<boost/noncopyable.hpp>

#include "Channel.h"
#include "Socket.h"

class EventLoop;
class InetAddress;

class Acceptor:boost::noncopyable
{
public:
    typedef boost::function<void (int sockfd,const InetAddress &)> NewConnectionCallback;
    Acceptor(EventLoop* loop, const InetAddress& listenAddr);

    void setNewConnectionCallback(const NewConnectionCallback& cb)
    { newConnectionCallback_ = cb; }

    bool listenning() const { return listenning_; }
    void listen();
private:
    void handleRead();//可读回调函数，绑定在acceptChannel_上
    EventLoop *loop_;//所属的EventLoop上
    Socket acceptSocket_;//listening socket
    Channel acceptChannel_;//管理listening socket的Channel
    NewConnectionCallback newConnectionCallback_;//连接回调函数
    bool listenning_;
};

#endif