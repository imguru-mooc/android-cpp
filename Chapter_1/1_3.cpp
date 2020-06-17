#if 1
#include <stdio.h>

class AAA
{
    int a;
public:
    AAA(int _a) 
    {
		a = _a;
		printf("AAA(%d)\n", a); 
    }
};

class BBB : public AAA
{
    int b;
public:
    BBB(int _b, int _a ) : AAA(_a)
    {
		b = _b;
		printf("BBB(%d)\n", b); 
    }
};

int main()
{
	BBB b(10, 20);
    return 0;
}
#endif

#if 0
#include <stdio.h>

class AAA
{
    int a;
public:
    AAA(int _a) 
    {
		a = _a;
		printf("AAA(%d)\n", a); 
    }
};

class BBB : public AAA
{
    int b;
public:
    BBB(int _b, int _a )
    {
		b = _b;
		AAA(_a)
		printf("BBB(%d)\n", b); 
    }
};

int main()
{
	BBB b(10, 20);
    return 0;
}
#endif

#if 0
#include <stdio.h>

class AAA
{
    int a;
public:
    AAA(int _a) 
    {
		a = _a;
		printf("AAA(%d)\n", a); 
    }
};

class BBB
{
	AAA aaa;
    int b;
public:
    BBB(int _b, int _a ):aaa(_a)
    {
		b = _b;
		printf("BBB(%d)\n", b); 
    }
};

int main()
{
	BBB b(10, 20);
    return 0;
}
#endif
#if 0
#include <stdio.h>

class AAA
{
    int a;
public:
    AAA(int _a) 
    {
		a = _a;
		printf("AAA(%d)\n", a); 
    }
};

class BBB
{
	AAA aaa;
    int b;
public:
    BBB(int _b) 
    {
		b = _b;
		printf("BBB(%d)\n", b); 
    }
};

int main()
{
	BBB b(10);
    return 0;
}
#endif
#if 0
#include <stdio.h>

class Int32
{
    int &data;
public:
    Int32(int &a) : data(a)
    {
		data = 20;
		printf("data=%d\n", data);
    }
};

int main()
{
	int j=10;
    Int32 i = j;
	printf("j=%d\n", j );
    return 0;
}
#endif
#if 0
#include <stdio.h>

class Int32
{
    int &data;
public:
    Int32(int &a)
    {
		data = a;
		data = 20;
		printf("data=%d\n", data);
    }
};

int main()
{
	int j=10;
    Int32 i = j;
	printf("j=%d\n", j );
    return 0;
}
#endif

#if 0
#include <stdio.h>

class Int32
{
    const int data;
public:
    Int32(int a):data(a)
    {
		printf("data=%d\n", data);
    }
};

int main()
{
    Int32 i = 0;
    return 0;
}
#endif

#if 0
#include <stdio.h>

class Int32
{
    const int data;
public:
    Int32(int a)
    {
		data = a;
    }
};

int main()
{
    Int32 i = 0;
    return 0;
}
#endif
