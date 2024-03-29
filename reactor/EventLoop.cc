#include"EventLoop.h"
#include<assert.h>
#include<poll.h>
#include<sys/eventfd.h>
#include<boost/bind.hpp>
#include"Poll.h"
#include"Channel.h"
#include<signal.h>
#include<stdio.h>


__thread EventLoop* t_loopInThisThread = 0;
const int kPollTimeMs = 10000;
static int createEventfd()
{
    int evtfd = ::eventfd(0,EFD_NONBLOCK | EFD_CLOEXEC);
    if(evtfd < 0)
    {
        perror("Failed in eventfd");
        abort();
    }
    return evtfd;
}
class IgnoreSigPipe
{
 public:
  IgnoreSigPipe()
  {
    ::signal(SIGPIPE, SIG_IGN);
  }
};

IgnoreSigPipe initObj;
EventLoop::EventLoop():looping_(false),//事件循环是否开始
threadId_(CurrentThread::tid()),//获取当前线程id
quit_(false),
poller_(new Poller(this)),//创建一个poll
timerQueue_(new TimerQueue(this)),
wakeupFd_(createEventfd()),//创建了eventfd作为线程间等待、唤醒
wakeupChannel_(new Channel(this,wakeupFd_))//创建wakeupChannel通道
{
    if(t_loopInThisThread){//判断是否已有EventLoop
        perror("Another EventLoop");
        exit(1);
    }
    else
        t_loopInThisThread=this;
    wakeupChannel_->setReadCallback(boost::bind(&EventLoop::handleRead,this));//设定wakeupChannel的回调函数
    wakeupChannel_->enableReading();
}
EventLoop::~EventLoop()
{
    assert(!looping_);
    ::close(wakeupFd_);
    t_loopInThisThread=NULL;
}
void EventLoop::loop()
{
    assert(!looping_);
    assertInLoopThread();//断言处于创建线程中
    looping_=true;
    quit_ = false;
    while(!quit_)
    {
        activeChannels_.clear();
        pollReturnTime_=poller_->poll(kPollTimeMs,&activeChannels_);//调用poll返回活跃的事件，也有可能被唤醒
        for(ChannelList::iterator it = activeChannels_.begin();it != activeChannels_.end();it++){
            (*it)->handleEvent(pollReturnTime_);//遍历通道来唤醒
        }
        doPendingFunctors();//处理用户回调函数
    }
    looping_ = false;
}
void EventLoop::quit()
{
    quit_=true;
    if(!isInLoopThread()){
        wakeup();
    }
}
void EventLoop::runInLoop(const Functor& cb)
{
    if(isInLoopThread()){
        cb();
    }
    else{
        queueInLoop(cb);
    }
}
void EventLoop::queueInLoop(const Functor& cb)
{
    {
        MutexLockGuard lock(mutex_);
        pendingFunctors_.push_back(cb);
    }
    if(!isInLoopThread() || callingPendingFunctors_){
        wakeup();
    }
}
TimerId EventLoop::runAt(const Timestamp& time, const TimerCallback& cb)
{
    return timerQueue_->addTimer(cb,time,0.0);
}
TimerId EventLoop::runAfter(double delay,const TimerCallback& cb)
{
    Timestamp time(addTime(Timestamp::now(),delay));
    return runAt(time,cb);
}
TimerId EventLoop::runEvery(double interval, const TimerCallback& cb)
{
    Timestamp time(addTime(Timestamp::now(),interval));
    return runAt(time,cb);
}
void EventLoop::updateChannel(Channel* channel)
{
    assert(channel->ownerLoop() == this);
    assertInLoopThread();
    poller_->updateChannel(channel);//将Channel指针传给Poller
}
void EventLoop::removeChannel(Channel* channel)
{
  assert(channel->ownerLoop() == this);
  assertInLoopThread();
  poller_->removeChannel(channel);
}
void EventLoop::abortNotInLoopThread()
{
    perror("EventLoop::abortNotInLoopThread - EventLoop");
    exit(1);
}
void EventLoop::wakeup()
{
    uint64_t one =1;
    ssize_t  n = ::write(wakeupFd_,&one,sizeof(one));
    if(n!=sizeof(one)){
        perror("EventLoop::wakeup() writes");
    }
}
void EventLoop::handleRead()
{
    uint64_t one = 1;
    ssize_t n = ::read(wakeupFd_, &one, sizeof (one));
    if (n != sizeof(one))
     {
      perror( "EventLoop::handleRead() reads ");
     }
}
void EventLoop::doPendingFunctors()
{
    std::vector<Functor> functors;
    callingPendingFunctors_=true;
    {
        MutexLockGuard lock(mutex_);
        functors.swap(pendingFunctors_);
    }
    for(size_t i =0;i<functors.size();i++){
        functors[i]();
    }
    callingPendingFunctors_=false;
}