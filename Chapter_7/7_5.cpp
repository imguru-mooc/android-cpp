#if 1
#include <iostream>
#include <mutex>
using namespace std;

void f4(int a, double d, const char* s)
{
	cout << "f4 : " << a << ", " << d << ", " << s << endl;
}
mutex m;
template<typename F, typename ... Types> void lockAndCall(F func, Types&&... arg)
{
	lock_guard<mutex> lock(m);
	func(forward<Types&&>(arg)...);
}
int main()
{
	lockAndCall(f4, 1, 3.4, "abcd");
	return 0;
}

#endif
#if 0
#include <iostream>
#include <mutex>
using namespace std;

void f1(int a) { cout << "f1 : " << a << endl; }
void f2(int& a) { cout << "f2 : " << a << endl; a = 10; }
void f3(int&& a) { cout << "f3 : " << a << endl; }
mutex m;
template<typename F, typename A> void lockAndCall(F func, A&& arg)
{
	lock_guard<mutex> lock(m);
	func(forward<A&&>(arg));
}
int main()
{
	int n = 0;
	lockAndCall(f1, 10); 
	lockAndCall(f2, n); 
	lockAndCall(f3, 10); 
	return 0;
}

#endif
#if 0
#include <iostream>
#include <mutex>
using namespace std;

void f1(int a) { cout << "f1 : " << a << endl; }
void f2(int& a) { cout << "f2 : " << a << endl; a = 10; }
void f3(int&& a) { cout << "f3 : " << a << endl; }

mutex m;
template<typename F, typename A> void lockAndCall(F func, A&& arg)
{
	lock_guard<mutex> lock(m);
	func(arg);
}
int main()
{
	int n = 0;
	lockAndCall(f1, 10); // ok
	lockAndCall(f2, n); // ok
	//lockAndCall(f3, 10); // error
	cout << n << endl; // ok 10
}

#endif

#if 0
#include <iostream>
#include <mutex>
using namespace std;

void f1(int a) { cout << "f1 : " << a << endl; }
void f2(int& a) { cout << "f2 : " << a << endl; a = 10; }
mutex m;

template<typename F, typename A> void lockAndCall(F func, A& arg)
{
	lock_guard<mutex> lock(m);
	func(arg);
}

template<typename F, typename A> void lockAndCall(F func, const A& arg)
{
	lock_guard<mutex> lock(m);
	func(arg);
}

int main()
{
	lockAndCall(f1, 10);
	int n = 0;
	lockAndCall(f2, n);
	cout << n << endl;
	return 0;
}

#endif

#if 0
#include <iostream>
#include <mutex>
using namespace std;

void f1(int a) { cout << "f1 : " << a << endl; }
void f2(int& a) { cout << "f2 : " << a << endl; a = 10; }
mutex m;

template<typename F, typename A> void lockAndCall(F func, A arg)
{
	lock_guard<mutex> lock(m);
	func(arg);
}

int main()
{
	lockAndCall(f1, 10);
	int n = 0;
	lockAndCall(f2, n);
	cout << n << endl; 
	return 0;
}
#endif

