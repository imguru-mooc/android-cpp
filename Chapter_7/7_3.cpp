#if 1
#include <iostream>
#include <algorithm>
using namespace std;

int&& foo() { return 10; }
void f(int&) { cout << "int&" << endl; }
void f(int&&) { cout << "int&&" << endl; }

int main()
{
	int&& rr1 = 10;
	int&& rr2 = foo();
	f(10); 
	f(foo()); 
	f(rr1); 
	f(rr2); 

	int n = 10;
	f(n); 
	f(static_cast<int&&>(n)); 
	f(move(n)); 
	return 0;
}
#endif

#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int x = 0;
int& foo() { return x; }
int goo() { return x; }
void f(int&) { cout << "int&" << endl; }
void f(const int&) { cout << "const int&" << endl; }
void f(int&&) { cout << "int&&" << endl; }

int main()
{
	int n = 10;
	f(n); 
	f(10); 
	f(foo()); 
	f(goo()); 
	return 0;
}
#endif

#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int x = 0;
int& foo() { return x; }
int goo() { return x; }
int main()
{
	int n = 10;
	int& lr1 = n; 
	int& lr2 = 10; 
	int& lr3 = foo(); 
	int& lr4 = goo(); 
	int&& rr1 = n; 
	int&& rr2 = 10; 
	int&& rr3 = foo(); 
	int&& rr4 = goo(); 
	return 0;
}
#endif

#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int x = 0;
int& foo() { return x; }
int goo() { return x; }

int main()
{
	foo() = 10; 
	goo() = 10; 
	int* p1 = &foo(); 
	int* p2 = &goo(); 
	return 0;
}
#endif

#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a = 42, b = 43;
	a = b; 
	b = a; 

	int c = a * b; 
	a * b = 42; 

	int* p1 = &a; 
	int* p2 = &10; 
	return 0;
}
#endif
