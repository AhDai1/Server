#ifndef CHANNEL_H
#define CHANNEL_H

#include "Timestamp.h"

#include<boost/function.hpp>
#include<boost/noncopyable.hpp>

class Timestamp;
class EventLoop;
class Channel:boost::noncopyable
{
public:
    typedef boost::function<void()> EventCallback;
    typedef boost::function<void(Timestamp)> ReadEventCallback;
    Channel(EventLoop* loop,int fd);
    ~Channel();
    void handleEvent(Timestamp receiveTime);
    void setReadCallback(const ReadEventCallback& cb)
    { readCallback_ = cb;}
    void setWriteCallback(const EventCallback& cb)
    { writeCallback_ = cb;}
    void setErrorCallback(const EventCallback& cb)
    { errCallback_ = cb;}
    void setCloseCallback(const EventCallback& cb)
    {closeCallback_ = cb;}

    int fd() const { return fd_; }
     int events() const { return events_; }
    void set_revents(int revt) { revents_ = revt; }
    bool isNoneEvent() const { return events_ == kNoneEvent; }

    void enableReading() { events_ |= kReadEvent; update(); }
    void enableWriting(){events_ |= kWriteEvent;update();}
    void disableWriting(){events_ &= ~kWriteEvent;update();}
    void disableAll(){ events_ = kNoneEvent; update();}
    bool isWriting(){return events_ &kWriteEvent;}

      int index() { return index_; }
     void set_index(int idx) { index_ = idx; }

    EventLoop* ownerLoop();
private:
    void update();

    static const int kNoneEvent;//poll description
    static const int kReadEvent;
    static const int kWriteEvent;

    EventLoop *loop_;

    const int fd_;//pollfd members
    int events_;
    int revents_;
    int index_;

    bool eventHanding_;
    //EventCallback readCallback_;
    ReadEventCallback readCallback_;
    EventCallback writeCallback_;
    EventCallback errCallback_;
    EventCallback closeCallback_;
};

#endif // !CHANNEL_H
