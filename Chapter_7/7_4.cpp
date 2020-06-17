#if 1
#include <iostream>
#include <type_traits>
using namespace std;
void hoo(const char** s, int* p, double* d)
{
	cout << "hoo(const char**, int*, double*)" << endl;
}
void hoo(const char* s, int a, double d)
{
	cout << "hoo(const char*, int, double)" << endl;
}
template<typename ... Types> void goo(Types ... args)
{
	hoo(args...); 
	hoo(*args...); 
}
template<typename ... Types> void foo(Types ... args)
{
	goo(&args...); 
} 
int main()
{
	foo("hello", 10, 3.4);
	return 0;
}
#endif
#if 0
#include <iostream>
#include <type_traits>
using namespace std;
template<typename ... Types> void foo(Types ... args)
{
	cout << sizeof...(Types) << endl;
	cout << sizeof...(args) << endl;
}
template<typename ... Types> class Test
{
	public:
		Test() { cout << sizeof...(Types) << endl; }
		Test(Types ... args) { cout << sizeof...(args) << endl; }
};
int main()
{
	foo();
	foo(1);
	foo(1, "A");
	foo(1, 3.4, "A");
	Test<int, int> t1;
	Test<int, int, double> t2(1, 1, 3.4);
	return 0;
}
#endif

#if 0
template<typename ... Types> void foo(Types ... args) {}
template<typename ... Types> class tuple {};
template<int ... N> class int_tuple {};

int main()
{
	foo();
	foo(1);
	foo(1, 3.4, "AA");
	tuple<int> t1;
	tuple<int, double> t2;
	int_tuple<> it0;
	int_tuple<3> it1;
	int_tuple<3, 4, 5> it3;
}
#endif

#if 0
#include <iostream>
#include <type_traits>
using namespace std;

void check(true_type ) { cout << "true" << endl; }
void check(false_type) { cout << "false" << endl; }
template<typename T> void foo(T a)
{
	if (is_pointer<T>::value)
		cout << "Pointer!!" << endl;
	else
		cout << "Not Pointer!!" << endl;
	check(is_pointer<T>());
}
int main()
{
	int n = 3;
	foo(n);
	foo(&n);
	return 0;
}
#endif

#if 0
#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> inline void printvImp(T v, false_type)
{ cout << v << endl; }

template<typename T> inline void printvImp(T v, true_type)
{ cout << v << ", " << *v << endl; }

template<typename T> void printv(T v)
{
	printvImp(v, is_pointer<T>());
}

int main()
{
	int n = 3;
	printv(n);
	printv(&n);
	return 0;
}
#endif

