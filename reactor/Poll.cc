#include"Channel.h"
#include"Poll.h"
#include<assert.h>
#include<poll.h>
//class Timestamp;

Poller::Poller(EventLoop* loop):ownerLoop_(loop)
{

}
Poller::~Poller()
{

}
Timestamp Poller::poll(int timeoutms, ChannelList* activeChannels)
{
    int numEvents = ::poll(&*pollfds_.begin(),pollfds_.size(),timeoutms);
    Timestamp now(Timestamp::now());
    if(numEvents>0){
        fillActiveChannels(numEvents,activeChannels);
    }
    else if(numEvents ==0){

    }
    else if(numEvents<0){
        perror("Poller::poll()");
    }
    return now;
}
void Poller::fillActiveChannels(int numEvents, ChannelList* activeChannels) const
{
    for(PollFdList::const_iterator pfd = pollfds_.begin();pfd != pollfds_.end() && numEvents > 0;pfd++){
        if(pfd->revents > 0){
            --numEvents;
            ChannelMap::const_iterator ch = channels_.find(pfd->fd);
            assert(ch != channels_.end());
            Channel* channel = ch->second;
            assert(channel->fd() == pfd->fd);
            channel->set_revents(pfd->revents);
            activeChannels->push_back(channel);
        }
    }
}
void Poller::updateChannel(Channel* channel)
{
    assertInLoopThread();
    if(channel->index()<0){//new one
        assert(channels_.find(channel->fd()) == channels_.end());
        struct pollfd pfd;
        pfd.fd = channel->fd();
        pfd.events = static_cast<short>(channel->events());
        pfd.revents =0;
        pollfds_.push_back(pfd);
        int index = static_cast<int>(pollfds_.size())-1;
        channel->set_index(index);
        channels_[pfd.fd] = channel;
    }
    else{
        assert(channels_.find(channel->fd()) != channels_.end());
        assert(channels_[channel->fd()] == channel);
        int index = channel->index();
        assert(index>=0&&index < static_cast<int>(pollfds_.size())-1);
        struct pollfd& pfd = pollfds_[index];
        assert(pfd.fd == channel->fd() || pfd.fd == 0);
        pfd.events = static_cast<short>(channel->events());
        pfd.revents = 0;
        if(channel->isNoneEvent()){
            pfd.fd = -1;
        }
    }
}