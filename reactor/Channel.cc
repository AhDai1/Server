#include"Channel.h"
#include"EventLoop.h"
#include<poll.h>
#include<assert.h>

const int Channel::kNoneEvent = 0;
const int Channel::kReadEvent = POLLIN | POLLPRI;
const int Channel::kWriteEvent = POLLOUT;
Channel::Channel(EventLoop* loop,int fdArg):
loop_(loop),//保存EventLoop的指针
fd_(fdArg),//描述符
events_(0),//用户关心的事件
revents_(0),//实际发生的事件
index_(-1),//记录当前fd在pollfd的位置
eventHanding_(false)
{

}
Channel::~Channel()
{
    assert(!eventHanding_);
}
void Channel::update()
{
    loop_->updateChannel(this);//将指针传到了EventLoop
}
void Channel::handleEvent(Timestamp receiveTime)
{
    eventHanding_=true;
    if(revents_ & POLLNVAL){
        perror("Channel::handle_event() POLLNVAL");
        exit(0);
    }
    if((revents_& POLLHUP) && !(revents_ & POLLIN))
    {
        if(closeCallback_) closeCallback_();
    }
    if(revents_ & (POLLERR | POLLNVAL)){
        if(errCallback_) errCallback_();
    }
    if(revents_ & (POLLIN | POLLPRI | POLLRDHUP)){
        if(readCallback_) readCallback_(receiveTime);
    }
    if(revents_ & POLLOUT){
        if(writeCallback_) writeCallback_();
    }
    eventHanding_=false;
}
EventLoop* Channel::ownerLoop()
{
    return loop_;
}