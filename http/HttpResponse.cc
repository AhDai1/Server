#include"HttpResponse.h"

void HttpResponse::setStatusCode(HttpStatusCode code)
{
    statusCode_=code;
}
void HttpResponse::setStatusMessage(const string& message)
{
    statusMessages_ = message;
}
void HttpResponse::setCloseConnection(bool on)
{
    closeConnection_ = on;
}
bool HttpResponse::closeConnection() const
{
    return closeConnection_;
}
void HttpResponse::setContentType(const string& contentType)
{
    addHeader("Content-Type", contentType);
}
void HttpResponse::addHeader(const string& key, const string& value)
{
    headers_[key] = value;
}
void HttpResponse::setBody(const string& body)
{
    body_ = body;
}
/**
 * Construct response  to Buffer
**/
void HttpResponse::appendToBuffer(Buffer *output) const
{
     char buf[32];
     snprintf(buf, sizeof buf, "HTTP/1.1 %d ",statusCode_);
     output->append(buf);
     output->append(statusMessages_);
     output->append("\r\n");
     if(closeConnection_){
         output->append("Connection: Close\r\n");
     }
     else{
         snprintf(buf, sizeof buf, "Content-Length: %zd\r\n", body_.size());
         output->append(buf);
         output->append("Connection: Keep-Alive\r\n");
     }

     for(map<string,string>::const_iterator it = headers_.begin(); it != headers_.end(); it++){
         output->append(it->first);
         output->append(": ");
         output->append(it->second);
         output->append("r\\n");
     }

     output->append("\r\n");
     output->append(body_);
}