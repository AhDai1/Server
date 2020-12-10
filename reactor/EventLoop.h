#ifndef EVENTLOOP_H
#define EVENTLOOP_H
#include<boost/noncopyable.hpp>
#include<boost/scoped_ptr.hpp>
#include<boost/function.hpp>
#include<vector>
#include"../thread/Thread.h"
#include"TimerId.h"
#include"Callbacks.h"
#include"TimerQueue.h"

class Channel;
class Poller;
class EventLoop : boost::noncopyable
{
public:
    typedef boost::function<void()> Functor;
    EventLoop();
    void runInLoop(const Functor &cb);
    void queueInLoop(const Functor &cb);
    ~EventLoop();
    void loop();
    void assertInLoopThread()
    {
        if(!isInLoopThread())
            {
                abortNotInLoopThread();
            }
    }
    bool isInLoopThread() const
    {
        return threadId_ == CurrentThread::tid();
    }
    void quit();

    TimerId runAt(const Timestamp& time, const TimerCallback& cb);
    TimerId runAfter(double delay,const TimerCallback& cb);
    TimerId runEvery(double interval, const TimerCallback& cb);

    void updateChannel(Channel* channel);
    void wakeup();
    void removeChannel(Channel* channel);


private:
    void abortNotInLoopThread();

    bool looping_;
    const pid_t threadId_;
    typedef std::vector<Channel*> ChannelList;
    bool   quit_;
    bool callingPendingFunctors_;
    boost::scoped_ptr<Poller> poller_;
    ChannelList activeChannels_;
    boost::scoped_ptr<TimerQueue> timerQueue_;
    int wakeupFd_;
    boost::scoped_ptr<Channel> wakeupChannel_;
    MutexLock mutex_;
    std::vector<Functor> pendingFunctors_;
    void handleRead();
    void doPendingFunctors();
};

#endif