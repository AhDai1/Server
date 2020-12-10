#ifndef EVENTLOOPTHREAD_H
#define EVENTLOOPTHREAD_H

#include"../thread/Condition.h"
#include"Mutex.h"
#include"../thread/Thread.h"
#include<boost/noncopyable.hpp>

class EventLoop;
class EventLoopThread:boost::noncopyable
{
public:
    EventLoopThread();
    ~EventLoopThread();
    EventLoop* startLoop();
private:
    void threadFunc();
    EventLoop*loop_;
    bool exiting_;
    Thread thread_;
    MutexLock mutex_;
    Condition cond_;
};

#endif