#if 1
#include <stdio.h>

void swap( int *a, int *b )
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

template<typename T>
void sort( int *a, int n, T cmp)
{
	int i,j;
	for(i=0; i<n-1; i++)
		for(j=0; j<n-1; j++ )
			if( cmp(a[j] , a[j+1]) )
				swap(a+j, a+j+1);
}

struct less
{
	__always_inline
	int operator()( int a, int b ) 
	{
		return a<b;
	}
};

struct greater
{
	__always_inline
	int operator()( int a, int b ) 
	{
		return a>b;
	}
};

int main()
{
	int a[] = {3,4,2,5,1};
	sort( a, 5, less() );
	for(int i=0; i<5; i++ )
		printf("%4d", a[i] );
	printf("\n");
	sort( a, 5, greater() );
	for(int i=0; i<5; i++ )
		printf("%4d", a[i] );
	printf("\n");
}

#endif
#if 0
#include <stdio.h>

struct Plus
{
	__always_inline
	int operator()(int a, int b)
	{
		return a + b;
	}
};
int main()
{
	Plus p;
	int n = p(1,2);
	printf("%d\n", n );
	return 0;
}

#endif
#if 0
#include <stdio.h>

void swap( int *a, int *b )
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void sort( int *a, int n, int(*cmp)(int,int))
{
	int i,j;
	for(i=0; i<n-1; i++)
		for(j=0; j<n-1; j++ )
			if( cmp(a[j] , a[j+1]) )
				swap(a+j, a+j+1);
}

int cmp1( int a, int b ) 
{
	return a>b;
}

int cmp2( int a, int b ) 
{
	return a<b;
}

int main()
{
	int a[] = {3,4,2,5,1};
	sort( a, 5, cmp2 );
	for(int i=0; i<5; i++ )
		printf("%4d", a[i] );
	printf("\n");
}

#endif

#if 0
#include <stdio.h>

void swap( int *a, int *b )
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void sort( int *a, int n )
{
	int i,j;
	for(i=0; i<n-1; i++)
		for(j=0; j<n-1; j++ )
			if( a[j] > a[j+1] )
				swap(a+j, a+j+1);
}

int main()
{
	int a[] = {3,4,2,5,1};
	sort( a, 5 );
	for(int i=0; i<5; i++ )
		printf("%4d", a[i] );
	printf("\n");
}

#endif

#if 0

#define __always_inline __attribute__((__always_inline__))
void foo( int a) {}
__always_inline void goo( int a) {}
//inline void goo( int a) {}

int main()
{
	foo(1);
	goo(1);

	void(*f)(int);

	int n=0;

	if ( n == 1 ) f = &goo;
	else          f = &foo;

	f(1); 
}

#endif

