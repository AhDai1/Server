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
    int numEvents = ::poll(&*pollfds_.begin(),pollfds_.size(),timeoutms);//poll调用
    Timestamp now(Timestamp::now());
    if(numEvents>0){
        fillActiveChannels(numEvents,activeChannels);//填充活跃的事件Channel
    }
    else if(numEvents ==0){

    }
    else if(numEvents<0){
        perror("Poller::poll()");
    }
    return now;//返回poll的return时间
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
        struct pollfd pfd;//pollfd结构体
        pfd.fd = channel->fd();
        pfd.events = static_cast<short>(channel->events());
        pfd.revents =0;
        //pollfds_是pollfd类型的vector，充当poll的第一个参数
        pollfds_.push_back(pfd);
        int index = static_cast<int>(pollfds_.size())-1;//重新计算索引，方便下次快速定位
        channel->set_index(index);
        channels_[pfd.fd] = channel;//channels_是fd和channel的一个map
    }
    else{
        assert(channels_.find(channel->fd()) != channels_.end());
        assert(channels_[channel->fd()] == channel);
        int index = channel->index();
        assert(index>=0&&index < static_cast<int>(pollfds_.size()));//////
        struct pollfd& pfd = pollfds_[index];
        assert(pfd.fd == channel->fd() || pfd.fd == -channel->fd()-1);
        pfd.events = static_cast<short>(channel->events());
        pfd.revents = 0;
        if(channel->isNoneEvent()){
            pfd.fd = -channel->fd()-1;
        }
    }
}
template<typename To, typename From>
inline To implicit_cast(From const &f) {
    return f;
}
void Poller::removeChannel(Channel* channel)
{
  assertInLoopThread();
  assert(channels_.find(channel->fd()) != channels_.end());
  assert(channels_[channel->fd()] == channel);
  assert(channel->isNoneEvent());
  int idx = channel->index();
  assert(0 <= idx && idx < static_cast<int>(pollfds_.size()));
  const struct pollfd& pfd = pollfds_[idx]; (void)pfd;
  assert(pfd.fd == -channel->fd()-1 && pfd.events == channel->events());
  size_t n = channels_.erase(channel->fd());
  assert(n == 1); (void)n;
  if (implicit_cast<size_t>(idx) == pollfds_.size()-1) {
    pollfds_.pop_back();
  } else {
    int channelAtEnd = pollfds_.back().fd;
    iter_swap(pollfds_.begin()+idx, pollfds_.end()-1);
    if (channelAtEnd < 0) {
      channelAtEnd = -channelAtEnd-1;
    }
    channels_[channelAtEnd]->set_index(idx);
    pollfds_.pop_back();
  }
}