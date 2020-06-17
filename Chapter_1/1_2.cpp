#if 1
#include <stdio.h>

class Int32
{
	int data;
public:
	void set( int a ) 
	{
		printf("Int32::set()\n");
		data = a;    
	}
};

int main()
{
	Int32 *p = 0;
	p->set(10 );	
	return 0;
}
#endif
#if 0
#include <stdio.h>

class Int32
{
	int data;
public:
	void set( int a ) 
	{
		printf("Int32::set()\n");
		data = a;    
	}
};

int main()
{
	Int32 i;
	void (Int32::*f1)(int) = &Int32::set;	
	(i.*f1)(10);
	return 0;
}
#endif

#if 0
#include <stdio.h>

class Int32
{
	int data;
public:
	void set( int a ) 
	{
		printf("Int32::set()\n");
		data = a;    
	}
};

int main()
{
	void (Int32::*f1)(int) = &Int32::set;	
	f1(10);
	return 0;
}
#endif

#if 0
#include <stdio.h>

class Int32
{
	int data;
public:
	void set( int a ) 
	{
		printf("Int32::set()\n");
		data = a;    
	}
};

int main()
{
	void (*f1)(int) = &Int32::set;	
	f1(10);
	return 0;
}
#endif
#if 0
#include <stdio.h>

class Int32
{
	int data;
public:
	void set( int a ) 
	{
		printf("Int32::set()\n");
		data = a;    
	}
};

int main()
{
	void (*f1)(int) = &set;	
	f1(10);
	return 0;
}
#endif

#if 0
#include <stdio.h>

void foo( int a )
{
	printf("foo()\n");
}

int main()
{
	void (*f1)(int) = &foo;	
	f1(10);
	return 0;
}
#endif

#if 0
#include <stdio.h>

class Int32
{
	int data;
public:
	void set( int a ) // void set( Int32 * this, int a )
	{
		data = a;     // this->data = a
	}
};

int main()
{
	Int32 i;

	i.set(10);  // Int32::set(&i, 10)
	return 0;
}
#endif

#if 0
#include <stdio.h>

class Int32
{
	int data;
public:
	void set( int a )
	{
		data = a;
	}
};

int main()
{
	Int32 i;

	i.set(10);
	return 0;
}
#endif
