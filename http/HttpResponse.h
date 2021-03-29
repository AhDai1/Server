#ifndef _HTTPRESPONSE_H_
#define _HTTPRESPONSE_H_

#include<iostream>
#include<string>
#include<map>
#include"../reactor/Buffer.h"
using namespace std;
class HttpResponse
{
public:
    enum HttpStatusCode{
        CODE_UNKNOW,
        CODE_200 = 200,
        CODE_301 = 301,
        CODE_400 = 400,
        CODE_404 = 404
    };
    explicit HttpResponse(bool close):statusCode_(CODE_UNKNOW),closeConnection_(close){}
    void setStatusCode(HttpStatusCode code);
    void setStatusMessage(const string& message);
    void setCloseConnection(bool on);
    bool closeConnection() const;
    void setContentType(const string &contentType);
    void addHeader(const string &key, const string &value);
    void setBody(const string &body);
    void appendToBuffer(Buffer *output) const;

private:
    map<string,string> headers_;
    HttpStatusCode statusCode_;
    string statusMessages_;
    bool closeConnection_;
    string body_;
};


#endif