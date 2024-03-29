#include"HttpServer.h"

void defaultHttpCallback(const HttpRequest &, HttpResponse* resp)
{
    resp->setStatusCode(HttpResponse::CODE_400);
    resp->setStatusMessage("Not Found");
    resp->setCloseConnection(true);
}

HttpServer::HttpServer(EventLoop *loop,const InetAddress& listenAddr):
    server_(loop, listenAddr), httpCallback_(defaultHttpCallback)
{
    server_.setConnectionCallback(boost::bind(&HttpServer::onConnection, this, _1));
    server_.setMessageCallback(boost::bind(&HttpServer::onMessage, this, _1, _2, _3));
}
HttpServer::~HttpServer(){}
void HttpServer::start()
{
    server_.start();
}

void HttpServer::onConnection(const TcpConnectionPtr &conn)
{
    if(conn->connected())
    {
        conn->setContext(HttpContext());
    }
}

void HttpServer::onMessage(const TcpConnectionPtr &conn, Buffer *buf, Timestamp receiveTime)
{
    HttpContext *context = boost::any_cast<HttpContext>(conn->getMutableContext());
    if(!context->parseRequest(buf, receiveTime)){
        conn->send("HTTP/1.1 400 Bad Request\r\n\r\n");
        conn->shutdown();
    }
    if(context->gotAll()){
        onRequest(conn, context->request());
        context->reset();
    }
}

void HttpServer::onRequest(const TcpConnectionPtr &conn, const HttpRequest& req)
{
    const string& connection = req.getHeader("Connection");
    bool close =(connection == "close") || (req.getVersion() == HttpRequest::HTTP10 && connection != "Keep-Alive");
    HttpResponse response(close);
    httpCallback_(req, &response);
    Buffer buf;
    response.appendToBuffer(&buf);
    conn->send(&buf);
    if(response.closeConnection()){
        conn->shutdown();
    } 
}