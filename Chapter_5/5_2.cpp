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
