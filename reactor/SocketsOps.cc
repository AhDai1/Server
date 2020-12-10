#include"SocketsOps.h"

#include<stdio.h>
#include<strings.h>
#include<sys/socket.h>
#include<unistd.h>
#include<boost/implicit_cast.hpp>
#include<stdlib.h>
template<typename To, typename From>
inline To implicit_cast(From const &f) {
    return f;
}
typedef struct sockaddr SA;
const SA* sockaddr_cast(const struct sockaddr_in* addr)
{
    return static_cast<const SA*>(implicit_cast<const void *>(addr));
}
SA* sockaddr_cast(struct sockaddr_in* addr)
{
  return static_cast<SA*>(implicit_cast<void*>(addr));
}

int sockets::createNonblockingOrDie()
{
    int sockfd = ::socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, IPPROTO_TCP);
    if(sockfd < 0){
        perror("sockets::createNonblockingOrDie");
        exit(0);
    }
    return sockfd;
}
void sockets::bindOrDie(int sockfd,const struct sockaddr_in& addr)
{
    int ret = ::bind(sockfd,sockaddr_cast(&addr),sizeof(addr));
    if(ret<0){
        perror("sockets::bindOrDie");
        exit(0);
    }
}
void sockets::listenOrDie(int sockfd)
{
  int ret = ::listen(sockfd, SOMAXCONN);
  if (ret < 0)
  {
    perror( "sockets::listenOrDie");
    exit(0);
  }
}
int sockets::accept(int sockfd, struct sockaddr_in* addr)
{
    socklen_t addrlen = sizeof(*addr);
    int connfd = ::accept4(sockfd,sockaddr_cast(addr),&addrlen, SOCK_NONBLOCK | SOCK_CLOEXEC);
    if(connfd < 0){
        perror("Socket::accept");
        exit(0);
    }
    return connfd;
}
void sockets::close(int sockfd)
{
    if(::close(sockfd) < 0){
        perror("sockets::close");
        exit(0);
    }
}
void sockets::toHostPort(char* buf, size_t size,const struct sockaddr_in& addr)
{
    char host[INET_ADDRSTRLEN] = "INVALID";
    ::inet_ntop(AF_INET, &addr.sin_addr, host, sizeof host);
    uint16_t port = sockets::networkToHost16(addr.sin_port);
    snprintf(buf, size, "%s:%u", host, port);
}
void sockets::fromHostPort(const char* ip, uint16_t port,struct sockaddr_in* addr)
{
    addr->sin_family = AF_INET;
    addr->sin_port=hostToNetwork16(port);
    if(::inet_pton(AF_INET,ip,&addr->sin_addr)<=0){
        perror("sockets::fromHostPort");
        exit(0);
    }
}
struct sockaddr_in sockets::getLocalAddr(int sockfd)
{
  struct sockaddr_in localaddr;
  bzero(&localaddr, sizeof localaddr);
  socklen_t addrlen = sizeof(localaddr);
  if (::getsockname(sockfd, sockaddr_cast(&localaddr), &addrlen) < 0)
  {
    perror("sockets::getLocalAddr");
    exit(0);
  }
  return localaddr;
}