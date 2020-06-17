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











