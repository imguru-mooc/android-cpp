#if 1
#include <stdio.h>
#include "StrongPointer.h"
#include "RefBase.h"

//-------------------------------------------------------------------
using namespace android;

class AAA;
class BBB;

class AAA : public RefBase
{
	public:
		sp<BBB> pb;
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void foo(){ printf("AAA::foo()\n"); }
};

class BBB : public RefBase
{
	public:
		sp<AAA> pa;
		BBB(){ printf("BBB::BBB()\n"); }
		~BBB(){ printf("BBB::~BBB()\n"); }
		void foo(){ printf("AAA::foo()\n"); }
};

int main()
{
	{
		sp<AAA> p1 = new AAA();
		sp<BBB> p2 = new BBB();
		p1->pb = p2;
		p2->pa = p1;
	}
	printf("step 1.\n");

	return 0;
}
#endif

#if 0
#include <stdio.h>
#include "StrongPointer.h"
#include "RefBase.h"

//-------------------------------------------------------------------
using namespace android;

class AAA : public RefBase
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void onFirstRef() { printf("onFirstRef()\n"); } 
		void foo(){ printf("AAA::foo()\n"); }
};

int main()
{
	sp<AAA> p1 = new AAA();
	sp<AAA> p2 = p1;
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include "StrongPointer.h"
#include "RefBase.h"

//-------------------------------------------------------------------
using namespace android;

class AAA : public RefBase
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void foo(){ printf("AAA::foo()\n"); }
};

int main()
{
	sp<AAA> p1 = new AAA();
	sp<AAA> p2 = p1;
	return 0;
}
#endif

#if 0
#include <stdio.h>

class RefBase
{
	int mRefs;
	public:
		RefBase():mRefs(0){ printf("RefBase::RefBase()\n"); }
		virtual ~RefBase(){ printf("RefBase::~RefBase()\n"); }
		void incStrong() { mRefs++; }
		void decStrong() { if( --mRefs == 0 ) delete this; }
};

template< typename T >
class sp
{
	T *mPtr;
	public:
	    sp(T *ptr) : mPtr(ptr) { mPtr->incStrong(); }
	    sp(const sp<T> &r) : mPtr(r.mPtr) { mPtr->incStrong(); }
	    ~sp() { 
			mPtr->decStrong();
		}
		T *operator->() { return mPtr; }
		T &operator*() { return *mPtr; }
};

//-------------------------------------------------------------------

class AAA : public RefBase
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void foo(){ printf("AAA::foo()\n"); }
};


int main()
{
	sp<AAA> p1 = new AAA();
	sp<AAA> p2 = p1;
	return 0;
}
#endif
#if 0
#include <stdio.h>
class AAA
{
	int mRefs;
	public:
		AAA():mRefs(0){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void foo(){ printf("AAA::foo()\n"); }

		void incStrong() { mRefs++; }
		void decStrong() { if( --mRefs == 0 ) delete this; }
};

template< typename T >
class sp
{
	T *mPtr;
	public:
	    sp(T *ptr) : mPtr(ptr) { mPtr->incStrong(); }
	    sp(const sp<T> &r) : mPtr(r.mPtr) { mPtr->incStrong(); }
	    ~sp() { 
			mPtr->decStrong();
		}
		T *operator->() { return mPtr; }
		T &operator*() { return *mPtr; }
};

int main()
{
	sp<AAA> p1 = new AAA();
	sp<AAA> p2 = p1;
	return 0;
}
#endif
#if 0
#include <stdio.h>
class AAA
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void foo(){ printf("AAA::foo()\n"); }
};

template< typename T >
class sp
{
	static int mRefs;
	T *mPtr;
	public:
	    sp(T *ptr) : mPtr(ptr) { mRefs++; }
	    sp(const sp<T> &r) : mPtr(r.mPtr) { mRefs++; }
	    ~sp() { 
			if( --mRefs == 0 )
				delete mPtr; 
		}
		T *operator->() { return mPtr; }
		T &operator*() { return *mPtr; }
};

template< typename T >
int sp<T>::mRefs = 0;

int main()
{
	sp<AAA> p1 = new AAA();
	sp<AAA> p2 = p1;
	return 0;
}
#endif

#if 0
#include <stdio.h>
class AAA
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void foo(){ printf("AAA::foo()\n"); }
};

template< typename T >
class sp
{
	T *mPtr;
	public:
	    sp(T *ptr) : mPtr(ptr) {}
	    ~sp() { delete mPtr; }
		T *operator->() { return mPtr; }
		T &operator*() { return *mPtr; }
};

int main()
{
	sp<AAA> p1 = new AAA();
	sp<AAA> p2 = p1;
	return 0;
}
#endif

#if 0
#include <stdio.h>
class AAA
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void foo(){ printf("AAA::foo()\n"); }
};

class BBB
{
	public:
		BBB(){ printf("BBB::BBB()\n"); }
		~BBB(){ printf("BBB::~BBB()\n"); }
		void foo(){ printf("BBB::foo()\n"); }
};

template< typename T >
class sp
{
	T *mPtr;
	public:
	    sp(T *ptr) : mPtr(ptr) {}
	    ~sp() { delete mPtr; }
		T *operator->() { return mPtr; }
		T &operator*() { return *mPtr; }
};

int main()
{
	sp<BBB> p = new BBB();
	p->foo(); // p.operator->()->foo();
	(*p).foo();
	return 0;
}
#endif

#if 0
#include <stdio.h>
class AAA
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void foo(){ printf("AAA::foo()\n"); }
};

class sp
{
	AAA *mPtr;
	public:
	    sp(AAA *ptr) : mPtr(ptr) {}
	    ~sp() { delete mPtr; }
		AAA *operator->() { return mPtr; }
		AAA &operator*() { return *mPtr; }
};

int main()
{
	sp p = new AAA();
	p->foo(); // p.operator->()->foo();
	(*p).foo();
	return 0;
}
#endif

#if 0
#include <stdio.h>
class AAA
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void foo(){ printf("AAA::foo()\n"); }
};

class sp
{
	AAA *mPtr;
	public:
	    sp(AAA *ptr) : mPtr(ptr) {}
	    ~sp() { delete mPtr; }
};

int main()
{
	sp p = new AAA();
	p->foo();
	return 0;
}
#endif


#if 0
#include <stdio.h>
class AAA
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
};

class sp
{
	AAA *mPtr;
	public:
	    sp(AAA *ptr) : mPtr(ptr) {}
	    ~sp() { delete mPtr; }
};

int main()
{
	sp p = new AAA();
	return 0;
}
#endif


#if 0
#include <stdio.h>
class AAA
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
};

int main()
{
	AAA *p = new AAA();
	delete p;
	return 0;
}
#endif

#if 0
#include <stdio.h>
class AAA
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
};

int main()
{
	AAA aaa;
	return 0;
}
#endif

