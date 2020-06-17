#if 1
#include <stdio.h>
#include <pthread.h>
#include "StrongPointer.h"
#include "RefBase.h"
#include "Thread.h"

using namespace android;

class MyThread : public Thread
{
public:
	bool threadLoop()
	{
		printf("MyThread::foo()\n");
		sleep(2);
		return true;
	}
};

int main()
{
	sp<Thread> thread = new MyThread;
	thread->run("MyThread");
	thread->join();
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <pthread.h>
#include "StrongPointer.h"
#include "RefBase.h"

using namespace android;

class Thread
{
	pthread_t thread;
public:
	virtual void foo(void) = 0;
	static void *_foo(void* data)
	{
		Thread *self = static_cast<Thread*>(data);
		self->foo();
		return 0;
	}
	void run() { pthread_create( &thread, 0, _foo, this ); }
	void join() { pthread_join( thread, 0 ); }
};

class MyThread : public Thread
{
public:
	void foo(void)
	{
		printf("MyThread::foo()\n");
	}
};

int main()
{
	MyThread thread;
	thread.run();
	thread.join();
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <pthread.h>
#include "StrongPointer.h"
#include "RefBase.h"

using namespace android;

class Thread
{
	pthread_t thread;
public:
	void foo(void)
	{
		printf("Thread::foo()\n");
		printf("%lu\n", thread );
	}
	static void *_foo(void* data)
	{
		Thread *self = static_cast<Thread*>(data);
		self->foo();
		return 0;
	}
	void run() { pthread_create( &thread, 0, _foo, this ); }
	void join() { pthread_join( thread, 0 ); }
};

int main()
{
	Thread thread;
	thread.run();
	thread.join();
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <pthread.h>
#include "StrongPointer.h"
#include "RefBase.h"

using namespace android;

class Thread
{
	pthread_t thread;
public:
	static void *foo(void* data)
	{
		printf("Thread::foo()\n");
		printf("%d\n", thread );
		return 0;
	}
	void run() { pthread_create( &thread, 0, foo, 0 ); }
	void join() { pthread_join( thread, 0 ); }
};

int main()
{
	Thread thread;
	thread.run();
	thread.join();
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <pthread.h>
#include "StrongPointer.h"
#include "RefBase.h"

using namespace android;

class Thread
{
	pthread_t thread;
public:
	void *foo(void* data)
	{
		printf("foo()\n");
		return 0;
	}
	void run() { pthread_create( &thread, 0, foo, 0 ); }
	void join() { pthread_join( thread, 0 ); }
};

int main()
{
	Thread thread;
	thread.run();
	thread.join();
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <pthread.h>
#include "StrongPointer.h"
#include "RefBase.h"

using namespace android;

void *foo(void* data)
{
	printf("foo()\n");
	return 0;
}

class Thread
{
	pthread_t thread;
public:
	void run() { pthread_create( &thread, 0, foo, 0 ); }
	void join() { pthread_join( thread, 0 ); }
};

int main()
{
	Thread thread;
	thread.run();
	thread.join();
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <pthread.h>
#include "StrongPointer.h"
#include "RefBase.h"

using namespace android;


void *foo(void* data)
{
	printf("foo()\n");
	return 0;
}

int main()
{
	pthread_t thread;
	pthread_create( &thread, 0, foo, 0 );
	pthread_join( thread, 0 );
	return 0;
}
#endif
