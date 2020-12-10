#include<iostream>
#include"EventLoop.h"
#include<poll.h>
#include"Channel.h"
#include<sys/timerfd.h>
EventLoop *g_loop;
void func()
{
    std::cout<<"func()"<<std::endl;
    g_loop->quit();
}
int main()
{
    EventLoop loop;
    g_loop = &loop;
    int timefd = ::timerfd_create(CLOCK_MONOTONIC,TFD_NONBLOCK | TFD_CLOEXEC);
    Channel channel(&loop,timefd);
    channel.setReadCallback(func);
    channel.enableReading();
    struct itimerspec howlong;
    bzero(&howlong,sizeof(howlong));
    howlong.it_value.tv_sec = 5;
    ::timerfd_settime(timefd,0,&howlong,NULL);
    loop.loop();
}