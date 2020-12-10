#ifndef POLL_H
#define POLL_H

#include<map>
#include<vector>
#include"EventLoop.h"
#include"Timestamp.h"

struct pollfd;



class Channel;
class Timestamp;
class Poller
{
public:
    typedef std::vector<Channel*> ChannelList;
    Poller(EventLoop *loop);
    ~Poller();
    Timestamp poll(int timeoutms, ChannelList* activeChannels);
    void updateChannel(Channel* channel);
    void assertInLoopThread() { ownerLoop_->assertInLoopThread(); }
private:
    void fillActiveChannels(int numEvents,ChannelList* activeChannels) const;
    typedef std::vector<struct pollfd> PollFdList;
    typedef std::map<int,Channel*> ChannelMap;//fd->Channel*
    EventLoop* ownerLoop_;
    PollFdList pollfds_;
    ChannelMap channels_;
};

#endif // !POLL_H
