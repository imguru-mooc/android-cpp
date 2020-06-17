#if 1
#include <stdio.h>
#include <pthread.h>
#include "StrongPointer.h"
#include "RefBase.h"
#include "Thread.h"

using namespace android;

template <typename TYPE>
class  Singleton
{
public:
    static TYPE* getInstance() {
        Mutex::Autolock _l(sLock);
        TYPE* instance = sInstance;
        if (instance == nullptr) {
            instance = new TYPE();
            sInstance = instance;
        }
        return instance;
    }
    
protected:
    ~Singleton() { }
    Singleton() { }

private:
    Singleton(const Singleton&);
    static Mutex sLock;
    static TYPE* sInstance;
};

#define ANDROID_SINGLETON_STATIC_INSTANCE(TYPE)                 \
    template<> Mutex  \
        (Singleton< TYPE >::sLock)(Mutex::PRIVATE);  \
    template<> TYPE* Singleton< TYPE >::sInstance(nullptr);  /* NOLINT */ \
    template class Singleton< TYPE >;

class AAA : public RefBase, public Singleton<AAA>
{
public:
	AAA(){printf("AAA::AAA()\n");}
	~AAA(){printf("AAA::~AAA()\n");}
};

ANDROID_SINGLETON_STATIC_INSTANCE(AAA);

int main()
{
	sp<AAA> p1 = AAA::getInstance();
	sp<AAA> p2 = AAA::getInstance();
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

class ProcessState;
Mutex& gProcessMutex = *new Mutex;
sp<ProcessState> gProcess;

class ProcessState : public virtual RefBase
{
public:
    static  sp<ProcessState>    self();

private:
    explicit  ProcessState();
};

ProcessState::ProcessState()
{
    printf("open(\"/dev/binder\", O_RDWR | O_CLOEXEC)\n");
}

sp<ProcessState> ProcessState::self()
{
    Mutex::Autolock _l(gProcessMutex);
    if (gProcess != nullptr) {
        return gProcess;
    }
    gProcess = new ProcessState();
    return gProcess;
}

int main()
{
	sp<ProcessState>p1 = ProcessState::self();
	sp<ProcessState>p2 = ProcessState::self();
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

class AAA : public RefBase
{
private:
	static sp<AAA> sProcess;
	AAA(){printf("AAA::AAA()\n");}
	AAA(const AAA &r){printf("AAA::AAA(const AAA&)\n");}
	~AAA(){printf("AAA::~AAA()\n");}
public:
    static  sp<AAA> self()
	{
		if (sProcess != nullptr) {
			return sProcess;
		}
		sProcess = new AAA;
		return sProcess;
	}
};

sp<AAA> AAA::sProcess;

int main()
{
	sp<AAA>p1 = AAA::self();
	sp<AAA>p2 = AAA::self();
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

class AAA 
{
private:
	static AAA *sProcess;
	AAA(){printf("AAA::AAA()\n");}
	AAA(const AAA &r){printf("AAA::AAA(const AAA&)\n");}
	~AAA(){printf("AAA::~AAA()\n");}
public:
    static  AAA* self()
	{
		if (sProcess != nullptr) {
			return sProcess;
		}
		sProcess = new AAA;
		return sProcess;
	}
};

AAA* AAA::sProcess=nullptr;

int main()
{
	AAA *p1 = AAA::self();
	AAA *p2 = AAA::self();
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

class AAA 
{
private:
	AAA(){printf("AAA::AAA()\n");}
	AAA(const AAA &r){printf("AAA::AAA(const AAA&)\n");}
	~AAA(){printf("AAA::~AAA()\n");}
};

int main()
{
	AAA a;
	AAA b;
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

class AAA 
{
public:
	AAA(){printf("AAA::AAA()\n");}
	~AAA(){printf("AAA::~AAA()\n");}
};

int main()
{
	AAA a;
	AAA b;
	return 0;
}
#endif

