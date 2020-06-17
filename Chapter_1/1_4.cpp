#if 1
#include <stdio.h>

class AAA
{
	static int data;
public:
	static void foo()
	{
		data = 20;
		printf("AAA::foo(), data=%d\n", data);
	}
};
int AAA::data = 0;
int main()
{
	AAA::foo();
    return 0;
}

#endif

#if 0
#include <stdio.h>

class AAA
{
	static int data;
};

int AAA::data = 0;

int main()
{
	AAA::foo();
    return 0;
}

#endif

#if 0
#include <stdio.h>

class AAA
{
public:
	static void foo()
	{
		printf("AAA::foo()\n");
	}
};

int main()
{
	void (*f1)() = &AAA::foo;
	f1();
    return 0;
}

#endif

#if 0
#include <stdio.h>

class AAA
{
public:
	static void foo()
	{
		printf("AAA::foo()\n");
	}
};

int main()
{
	AAA::foo();
    return 0;
}

#endif
#if 0
#include <stdio.h>

class AAA
{
public:
	static void foo()
	{
		printf("AAA::foo()\n");
	}
};

int main()
{
	AAA a;
	a.foo();
    return 0;
}

#endif
#if 0
#include <stdio.h>

class Int32
{
    int data;
public:
    Int32(int a):data(a) {}
	void set(int a) { data = a; }
	void display() const 
	{
		printf("%d\n", data );
	}
};

int main()
{
    const Int32 i = 10;
	void (Int32::*f1)() const  = &Int32::display;
	(i.*f1)();
    return 0;
}

#endif

#if 0
#include <stdio.h>

class Int32
{
    int data;
public:
    Int32(int a):data(a) {}
	void set(int a) { data = a; }
	void display() const 
	{
		printf("%d\n", data );
	}
};

int main()
{
    const Int32 i = 10;
	i.display();
    return 0;
}

#endif

#if 0
#include <stdio.h>

class Int32
{
    int data;
public:
    Int32(int a):data(a) {}
	void set(int a) { data = a; }
	void display() 
	{
		printf("%d\n", data );
	}
};

int main()
{
    const Int32 i = 10;
	i.display();
    return 0;
}

#endif

#if 0
#include <stdio.h>

class Int32
{
    int data;
public:
    Int32(int a):data(a) {}
	void set(int a) { data = a; }
	void display()
	{
		printf("%d\n", data );
	}
};

int main()
{
    Int32 i = 10;
	i.display();
    return 0;
}

#endif
