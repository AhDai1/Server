#ifndef SOCKET_H
#define SOCKET_H

#include<boost/noncopyable.hpp>


class InetAddress;

class Socket:boost::noncopyable
{
public:
    explicit Socket(int sockfd):sockfd_(sockfd){}
    ~Socket();
    int fd() const { return sockfd_; }
    void bindAddress(const InetAddress& localaddr);
    void listen();
    int accept(InetAddress* peeraddr);
    void setReuseAddr(bool on);

private:
    const int sockfd_;
};

#endif