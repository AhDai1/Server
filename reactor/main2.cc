#include<iostream>
#include"EventLoop.h"
#include<poll.h>
#include"Channel.h"
#include<sys/timerfd.h>
EventLoop *g_loop;
void timeout(Timestamp receiveTime)
{
    printf("%s Timeout!\n", receiveTime.toFormattedString().c_str());
    g_loop->quit();
}
int main()
{
    printf("%s started\n", Timestamp::now().toFormattedString().c_str());
    EventLoop loop;
    g_loop = &loop;
    int timefd = ::timerfd_create(CLOCK_MONOTONIC,TFD_NONBLOCK | TFD_CLOEXEC);
    Channel channel(&loop,timefd);
    channel.setReadCallback(timeout);
    channel.enableReading();
    struct itimerspec howlong;
    bzero(&howlong,sizeof(howlong));
    howlong.it_value.tv_sec = 5;
    ::timerfd_settime(timefd,0,&howlong,NULL);
    loop.loop();
}