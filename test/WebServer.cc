

#include <iostream>
#include <map>
#include <string>

// #include "../http/HttpServer.h"
// #include "../http/HttpRequest.h"
// #include "../http/HttpResponse.h"
// #include "../http/Util.h"
#include "../reactor/HttpServer.h"
#include "../reactor/HttpRequest.h"
#include "../reactor/HttpResponse.h"
#include "../reactor/Util.h"
#include "../reactor/EventLoop.h"
using namespace std;


void onRequest(const HttpRequest& req, HttpResponse* resp)
{
    string path=Util::ConstructPath(req.path());
    string extent=Util::GetExtent(path);
    string contentType="";
    Util::GetContentType(extent,contentType);
    string content=Util::GetContent(path);
    if(content.empty())
    {
        resp->setStatusCode(HttpResponse::CODE_404);
        resp->setStatusMessage("Not Found");
    }
    else
    {
        resp->setBody(content);
        resp->setStatusCode(HttpResponse::CODE_200);
        resp->setStatusMessage("OK");
        resp->setContentType(contentType);
    } 
}

int main()
{


    EventLoop loop;
    HttpServer server(&loop, InetAddress(8000) );
    server.setHttpCallback(onRequest);
    server.start();
    loop.loop();
    return 0;
}