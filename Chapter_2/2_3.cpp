#if 1
#include <stdio.h>
#include "StrongPointer.h"
#include "RefBase.h"

//-------------------------------------------------------------------
using namespace android;

class AAA : public RefBase
{
	int data;
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void foo()
		{ 
			printf("AAA::foo()\n"); 
			data = 20;
		}
};

int main()
{
	{
		wp<AAA> p1 = new AAA;
		{
			sp<AAA> p2 = p1.promote();
		} // ~AAA()
		printf("step 1.\n");
		if( p1.promote() == 0 )
			printf("이미 객체가 소멸됨\n");
		else
			p1.promote()->foo(); // AAA::foo(this);
	}
	printf("step 2.\n");

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
	int data;
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void foo()
		{ 
			printf("AAA::foo()\n"); 
			//data = 20;
		}
};

int main()
{
	{
		wp<AAA> p1 = new AAA;
		{
			sp<AAA> p2 = p1.promote();
		} // ~AAA()
		printf("step 1.\n");
		p1.promote()->foo(); // AAA::foo(this);
	}
	printf("step 2.\n");

	return 0;
}
#endif

#if 0
#include <stdio.h>
#include "StrongPointer.h"
#include "RefBase.h"
using namespace android;

class AAA : public RefBase {
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void foo() { printf("AAA::foo()\n"); }
};

int main() {
	{
		wp<AAA> p1 = new AAA;
		sp<AAA> p2 = p1.promote();
		p2->foo(); 
	}
	printf("step 1.\n");

	return 0;
}
#endif

#if 0
#include <stdio.h>
#include "StrongPointer.h"
#include "RefBase.h"

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
	{
		wp<AAA> p1 = new AAA();
		p1->foo();
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

class AAA;
class BBB;

class AAA : public RefBase
{
	public:
		wp<BBB> pb;
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void foo(){ printf("AAA::foo()\n"); }
};

class BBB : public RefBase
{
	public:
		wp<AAA> pa;
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


