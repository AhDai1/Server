#include"HttpContext.h"
/**
 *  Parse the request line
 **/
bool HttpContext::processRequestLine(const char *begin, const char *end)
{
    bool succeed = false;
    const char *start = begin;
    const char *space = find(start,end,' ');
    if(space != end && request_.setMethod(start,space)){
        start  = space + 1;
        space = find(start,end,' ');
        if(space != end){
            const char *question = find(start,space,'?');
            if(question != space){
                request_.setPath(start, question);
                request_.setQuery(question, space);
            }
            else{
                request_.setPath(start, space);
            }
            start = space + 1;
            succeed = end - start == 8 && equal(start, end - 1, "HTTP/1.");
            if(succeed){
                if(*(end - 1) == '1'){
                    request_.setVersion(HttpRequest::HTTP11);
                }
                else if(*(end - 1) == '0'){
                    request_.setVersion(HttpRequest::HTTP10);
                }
                else{
                    succeed = false;
                }
            }
        }
    }
    return succeed;
}
/**
 * Parsing request
**/
bool HttpContext::parseRequest(Buffer *buf, Timestamp receiveTime)
{
    bool ok = true;
    bool hasMore = true;
    while(hasMore){
        if(state_ == kExpectRequestLine){
            const char *crlf = buf->findCRLF();
            if(crlf){
                ok = processRequestLine(buf->peek(), crlf);
                if(ok){
                    request_.setReceiveTime(receiveTime);
                    buf->retrieveUntil(crlf + 2);
                    state_ = kExpectHeaders;
                }
                else{
                    hasMore = false;
                }
            }
            else{
                hasMore = false;
            }
        }
        else if(state_ == kExpectHeaders){
            const char * crlf = buf->findCRLF();
            if(crlf){
                const char *colon = find(buf->peek(), crlf, ':');
                if(colon != crlf){
                    request_.addHeader(buf->peek(), colon, crlf);
                }
                else{
                    state_=  kGotAll;
                    hasMore = false;
                }
                buf->retrieveUntil(crlf + 2);
            }
            else{
                hasMore = false;
            }
        }
        else if(state_ == kExpectBody){

        }
    }
    return ok;
}