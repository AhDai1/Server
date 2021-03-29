#ifndef _HTTPREQUEST_H_
#define _HTTPREQUEST_H_

#include<iostream>
#include<boost/noncopyable.hpp>
#include<string>
#include<map>
#include"../reactor/Timestamp.h"
using namespace std;


class HttpRequest{
public:
    enum Method{
        INVALID,
        GET,
        POST,
        HEAD,
        PUT,
        DELETE
    };
    enum Version{
        UNKNOW,
        HTTP10,
        HTTP11
    };
    HttpRequest();
    void setVersion(Version v);
    Version getVersion() const;
    bool setMethod(const char *start, const char *end);
    Method method() const;
    const char *methodString() const;
    void setPath(const char* start, const char *end);
    const string& path() const;
    void setQuery(const char *start,const char* end);
    const string& query() const;
    void setReceiveTime(Timestamp t);
    Timestamp receiveTime() const;
    void addHeader(const char *start,const char *colon,const char *end);
    string getHeader(const string& filed) const;
    const map<string,string>& headers() const;
    void swap(HttpRequest& that);

private:
    Method method_;
    Version version_;
    string path_;
    string query_;
    Timestamp receivetime_;
    map<string,string>headers_;
};



#endif 
