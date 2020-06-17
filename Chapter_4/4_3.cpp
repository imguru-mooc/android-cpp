#if 1
#include <stdio.h>
#include <pthread.h>
#include "StrongPointer.h"
#include "RefBase.h"
#include "Thread.h"
#include "Mutex.h"
#include "Condition.h"

using namespace android;

Mutex mutex;
Condition cond;
class Producer: public Thread
{
public:
	bool threadLoop()
	{
		Mutex::Autolock ll(mutex);
		for(int i=0; i<3; i++)
		{
			sleep(1);
			printf("생산중...\n");
		}
		printf("생산완료\n");
		cond.signal();
				
		return false;
	}
};
class Consumer : public Thread
{
public:
	bool threadLoop()
	{
		Mutex::Autolock ll(mutex);
		cond.wait(mutex);
		for(int i=0; i<3; i++)
		{
			sleep(1);
			printf("소비중...\n");
		}
		printf("소비완료\n");
				
		return false;
	}
};

int main()
{
	sp<Thread> pro = new Producer;
	pro->run("Producer");
	sp<Thread> con = new Consumer;
	con->run("Consumer");

	pro->join();
	con->join();
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

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

class Producer: public Thread
{
public:
	bool threadLoop()
	{
		pthread_mutex_lock(&mutex);
		for(int i=0; i<3; i++)
		{
			sleep(1);
			printf("생산중...\n");
		}
		printf("생산완료\n");
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
				
		return false;
	}
};
class Consumer : public Thread
{
public:
	bool threadLoop()
	{
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&cond, &mutex);
		for(int i=0; i<3; i++)
		{
			sleep(1);
			printf("소비중...\n");
		}
		printf("소비완료\n");
		pthread_mutex_unlock(&mutex);
				
		return false;
	}
};

int main()
{
	sp<Thread> pro = new Producer;
	pro->run("Producer");
	sp<Thread> con = new Consumer;
	con->run("Consumer");

	pro->join();
	con->join();
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

class Producer: public Thread
{
public:
	bool threadLoop()
	{
		for(int i=0; i<3; i++)
		{
			sleep(1);
			printf("생산중...\n");
		}
		printf("생산완료\n");
				
		return false;
	}
};
class Consumer : public Thread
{
public:
	bool threadLoop()
	{
		for(int i=0; i<3; i++)
		{
			sleep(1);
			printf("소비중...\n");
		}
		printf("소비완료\n");
				
		return false;
	}
};

int main()
{
	sp<Thread> pro = new Producer;
	pro->run("Producer");
	sp<Thread> con = new Consumer;
	con->run("Consumer");

	pro->join();
	con->join();
	return 0;
}
#endif
