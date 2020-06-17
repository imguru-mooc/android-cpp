#if 1
#include <stdio.h>
#include <pthread.h>
#include "StrongPointer.h"
#include "RefBase.h"
#include "Thread.h"

using namespace android;

static pthread_mutex_t gTLSMutex = PTHREAD_MUTEX_INITIALIZER;
static bool gHaveTLS(false);
static pthread_key_t gTLS = 0;


class IPCThreadState 
{
	public:
		static  IPCThreadState*     self();
		static void threadDestructor(void *st)
		{
			delete (IPCThreadState*)st;
		}

	private:
		IPCThreadState();
		~IPCThreadState();
};

IPCThreadState::IPCThreadState()
{
    pthread_setspecific(gTLS, this);
	printf("IPCThreadState::IPCThreadState()\n");
}

IPCThreadState::~IPCThreadState()
{
	printf("IPCThreadState::~IPCThreadState()\n");
}

IPCThreadState* IPCThreadState::self()
{
    if (gHaveTLS) {
restart:
        const pthread_key_t k = gTLS;
        IPCThreadState* st = (IPCThreadState*)pthread_getspecific(k);
        if (st) return st;
        return new IPCThreadState;
    }

    pthread_mutex_lock(&gTLSMutex);
    if (!gHaveTLS) {
        int key_create_value = pthread_key_create(&gTLS, threadDestructor);
        if (key_create_value != 0) {
            pthread_mutex_unlock(&gTLSMutex);
            return nullptr;
        }
        gHaveTLS = true;
    }
    pthread_mutex_unlock(&gTLSMutex);
    goto restart;
}

class AAA : public Thread
{
	public : 
		bool threadLoop()
		{
			IPCThreadState *t1 = IPCThreadState::self();
			IPCThreadState *t2 = IPCThreadState::self();
			IPCThreadState *t3 = IPCThreadState::self();
			return false;
		}
};

class BBB : public Thread
{
	public : 
		bool threadLoop()
		{
			IPCThreadState *t1 = IPCThreadState::self();
			IPCThreadState *t2 = IPCThreadState::self();
			return false;
		}
};

int main()
{
	sp<AAA> t1 = new AAA;	
	sp<AAA> t2 = new AAA;	
	t1->run("AAA");
	t2->run("BBB");
	t1->join();
	t2->join();
	sleep(3);
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

pthread_key_t key;
void Destructor( void *data )
{
	printf("Destructor()\n");
	delete (int*)data;
}

void foo(void)
{
	int *count;
	count = (int*)pthread_getspecific( key );
	if( count == 0 )
	{
		count = new int(0);
		pthread_setspecific( key, count );
	}
	printf("foo() : %d\n", ++*count );
}

class AAA : public Thread
{
	public : 
		bool threadLoop()
		{
			foo();
			foo();
			foo();
			return false;
		}
};

class BBB : public Thread
{
	public : 
		bool threadLoop()
		{
			foo();
			foo();
			return false;
		}
};

int main()
{
	pthread_key_create(&key, Destructor);
	sp<AAA> t1 = new AAA;	
	sp<AAA> t2 = new AAA;	
	t1->run("AAA");
	t2->run("BBB");
	t1->join();
	t2->join();
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

void Destructor( void *data )
{
	printf("Destructor()\n");
}

int main()
{
	pthread_key_t key;
	pthread_key_create(&key, Destructor);
	printf("key=%d\n", key );
	pthread_key_create(&key, Destructor);
	printf("key=%d\n", key );
	pthread_key_create(&key, Destructor);
	printf("key=%d\n", key );
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

int count=0;
void foo(void)
{
	printf("foo() : %d\n", ++count );
}

class AAA : public Thread
{
	public : 
		bool threadLoop()
		{
			foo();
			foo();
			foo();
			return false;
		}
};

class BBB : public Thread
{
	public : 
		bool threadLoop()
		{
			foo();
			foo();
			return false;
		}
};

int main()
{
	sp<AAA> t1 = new AAA;	
	sp<AAA> t2 = new AAA;	
	t1->run("AAA");
	t2->run("BBB");
	t1->join();
	t2->join();
	return 0;
}
#endif
