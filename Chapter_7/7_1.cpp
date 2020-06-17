#if 0
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

int main() 
{
	pair<int,pair<int,int>> p = make_pair(1,make_pair(2,3));
	cout << p.first << ' ' << p.second.first << ' ' << p.second.second << '\n';

	tuple<int, int, int> a(1,2,3);
    tuple<int, int, int> b = make_tuple(1,2,3);

	tuple<int, int, int> t(1,2,3);
	int t1 = get<0>(t);
	int t2 = get<1>(t);
	int t3 = get<2>(t);
	cout << t1 << ' ' << t2 << ' ' << t3 << '\n';
	return 0;
}

#endif
#if 0
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() 
{
	vector<int> v1;
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	vector<int> v2 = {2, 3, 5, 7};

	vector<int> a = {1,2,3,4,5};
	pair<string, int> p = {"Year", 2020};
	map<string, int> age = { {"Kim", 26}, {"Lee", 26} };
	vector<vector<int>> matrix = {{1, 2}, {3, 4}};
	vector<pair<int,int>> l = {{1, 2}, {3, 4}, {5, 6}};
	return 0;
}

#endif
#if 0
#include <stdio.h>
#include <vector>

void foo(int)
{
	printf("foo(int)\n");
}
void foo(int*)
{
	printf("foo(int*)\n");
}

int main() 
{
	//foo(NULL);
	foo(nullptr);
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <vector>

void foo(int)
{
	printf("foo(int)\n");
}
void foo(int*)
{
	printf("foo(int*)\n");
}

int main() 
{
	//foo(NULL);
	foo(nullptr);
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>

template <typename T> 
using Vec = std::vector<T>;

int main() 
{
	Vec<int> v(10); // std::vector<int>

	using String = std::string;
	String s {"foo"};
}
#endif

#if 0
#include <iostream>

template <int N>
struct A {
	int operator()() { return N; }
};

int main() {
	int n;
	const int i=n;
	constexpr int j=n;

	constexpr int N = 10;
	A<N> a;  
	std::cout << a() << std::endl;

	constexpr int number = 3;
	enum B { x = number, y, z };  
	std::cout << B::x << std::endl;
}
#endif

#if 0
#include <iostream>

constexpr int square(int x) {
	return x * x;
}

int square2(int x) {
	return x * x;
}

int main() {
	int a = square(2);   // movl   $0x4,-0x8(%rbp)

	int b = square2(2);  // mov    $0x2,%edi
	// callq  1169 <_Z7square2i>
	// mov    %eax,-0x4(%rbp)
}
#endif

#if 0
#include <iostream>

template <int N>
struct A {
	int operator()() { return N; }
};

int main() {
	int n;
	const int i=n;
	constexpr int j=n;

	constexpr int N = 10;
	A<N> a;  
	std::cout << a() << std::endl;

	constexpr int number = 3;
	enum B { x = number, y, z };  
	std::cout << B::x << std::endl;
}
#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v(5, 0);
	vector<int>::iterator p1 = v.begin();

	for (; p1 != v.end(); p1++) 
		cout << *p1 << endl;


	auto p2 = v.begin();
	decltype(v.begin()) p3;
	for (auto n : v) 
		cout << n << endl;

	//int& r1 = 0; // error
	int&& r2 = 0; // ok
	return 0;
}
#endif
