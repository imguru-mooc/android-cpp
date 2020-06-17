#if 1
#include <stdio.h>
#include <pthread.h>
#include "StrongPointer.h"
#include "RefBase.h"
#include "Thread.h"
#include "Mutex.h"

using namespace android;

Mutex mutex;
int sum = 0;

class MyThread : public Thread
{
public:
	bool threadLoop()
	{
		int local;
		for(int i=0; i<10000000; i++)
		{
			Mutex::Autolock ll(mutex);
			local = sum;
			local = local + 1;
			sum = local;
		}
				
		return false;
	}
};

int main()
{
	sp<Thread> thread1 = new MyThread;
	thread1->run("MyThread1");
	sp<Thread> thread2 = new MyThread;
	thread2->run("MyThread2");

	thread1->join();
	thread2->join();
	printf("sum = %d\n", sum );
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <pthread.h>
#include "StrongPointer.h"
#include "RefBase.h"
#include "Thread.h"
#include "Mutex.h"

using namespace android;

Mutex mutex;
int sum = 0;

class MyThread : public Thread
{
public:
	bool threadLoop()
	{
		int local;
		for(int i=0; i<10000000; i++)
		{
			mutex.lock();
			local = sum;
			local = local + 1;
			sum = local;
			mutex.unlock();
		}
				
		return false;
	}
};

int main()
{
	sp<Thread> thread1 = new MyThread;
	thread1->run("MyThread1");
	sp<Thread> thread2 = new MyThread;
	thread2->run("MyThread2");

	thread1->join();
	thread2->join();
	printf("sum = %d\n", sum );
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <pthread.h>
#include "StrongPointer.h"
#include "RefBase.h"
#include "Thread.h"

using namespace android;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int sum = 0;

class MyThread : public Thread
{
public:
	bool threadLoop()
	{
		int local;
		for(int i=0; i<10000000; i++)
		{
			pthread_mutex_lock(&mutex);
			local = sum;
			local = local + 1;
			sum = local;
			pthread_mutex_unlock(&mutex);
		}
				
		return false;
	}
};

int main()
{
	sp<Thread> thread1 = new MyThread;
	thread1->run("MyThread1");
	sp<Thread> thread2 = new MyThread;
	thread2->run("MyThread2");

	thread1->join();
	thread2->join();
	printf("sum = %d\n", sum );
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <pthread.h>
#include "StrongPointer.h"
#include "RefBase.h"
#include "Thread.h"

using namespace android;

int sum = 0;

class MyThread : public Thread
{
public:
	bool threadLoop()
	{
		int local;
		for(int i=0; i<10000000; i++)
		{
			local = sum;
			local = local + 1;
			sum = local;
		}
				
		return false;
	}
};

int main()
{
	sp<Thread> thread1 = new MyThread;
	thread1->run("MyThread1");
	sp<Thread> thread2 = new MyThread;
	thread2->run("MyThread2");

	thread1->join();
	thread2->join();
	printf("sum = %d\n", sum );
	return 0;
}
#endif
