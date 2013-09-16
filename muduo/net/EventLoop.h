
#ifndef MUDUO_NET_EVENTLOOP_H
#define MUDUO_NET_EVENTLOOP_H

#include <vector>
#include <muduo/base/Mutex.h>
#include <muduo/base/Thread.h>

using namespace muduo;


class EventLoop
{
 public:
    EventLoop();
    ~EventLoop();

    void loop();
    void assertInLoopThread();
    bool isInLoopThread() const { return threadId_ == CurrentThread::tid(); }
    static EventLoop* getEventLoopOfCurrentThread();

 private:
    void abortNotInLoopThread();
    bool looping_;
    const pid_t threadId_;
};


#endif  // MUDUO_NET_EVENTLOOP_H
