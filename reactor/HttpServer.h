#ifndef _HTTPSERVER_H
#define _HTTPSERVER_H
#include"../reactor/EventLoop.h"
#include"../reactor/TcpServer.h"
#include<boost/bind.hpp>
#include<boost/function.hpp>
#include<iostream>
#include<string>
#include"HttpContext.h"
#include"HttpRequest.h"
#include"HttpResponse.h"
using namespace std;


class HttpServer
{
public:
    HttpServer(EventLoop *loop,const InetAddress& listenAddr);
    ~HttpServer();
    //EventLoop* getLoop() const {return server_.}
    void setHttpCallback(const HttpCallback &cb){httpCallback_ = cb;}
    void start();
    
private:
    void onConnection(const TcpConnectionPtr &conn);
    void onMessage(const TcpConnectionPtr &conn, Buffer *buf, Timestamp receiveTime);
    void onRequest(const TcpConnectionPtr &conn, const HttpRequest &req);
    TcpServer server_;
    HttpCallback httpCallback_;
};

#endif