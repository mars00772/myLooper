
#include <muduo/net/EventLoop.h>
#include <muduo/base/Thread.h>
#include <stdio.h>

using namespace muduo;



void threadFunc()
{
	printf("threadFunc: pid = %d ,tid = %d\n",getpid(),muduo::CurrentThread::tid());
	EventLoop loop;
	loop.loop();
}

int main()
{
	printf("main(): pid = %d, tid = %d\n", getpid(), CurrentThread::tid());
	EventLoop loop;

	muduo::Thread thread(threadFunc);
	thread.start();
	loop.loop();
	pthread_exit(NULL);
	return 0;
}