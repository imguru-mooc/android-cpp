#if 1
#include <iostream>
#include <algorithm>
using namespace std;

class closure_object
{
	private: const int value1, value2;
	public:
		closure_object(int n1, int n2) : value1(n1), value2(n2) {}
		int operator()(int n) const { return n + value1 + value2; }
};

int main()
{
	int v1 = 1, v2 = 2;
	auto f1 = [v1, v2](int n) { return n + v1 + v2; };
	cout << f1(10) << endl;

	auto f2 = closure_object(v1, v2);
	cout << f2(10) << endl;
	return 0;
}
#endif
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int v1 = 2;
	int v2 = 3;
	int v3 = 4;
	//auto f1 = [](int n) { return n + v1 + v2; }; 
	auto f2 = [v1, v2](int n) { return n + v1 + v2; };
	auto f3 = [=](int n) { return n + v1 + v2 + v3; };

	//auto f4 = [v1](int n) { return v1 = n; }; 
	auto f5 = [&v1](int n) { return v1 = n; }; 
	auto f6 = [&](int n) { return v1 = n; v2 = n; }; 
	return 0;
}
#endif

#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	auto f1 = [](int a, int b) { return a + b; };
	auto f2 = [](int a, int b) { return a + b; };
	cout << typeid(f1).name() << endl;
	cout << typeid(f2).name() << endl;
	return 0;
}
#endif

#if 0
#include <iostream>
#include <algorithm>
using namespace std;

class closure_object
{
	public:
		void operator()(int n) const
		{
			cout << n << endl;
		}
};

int main()
{
	int x[] = { 1,2,3,4,5 };
	for_each(x, x + 5, [](int n) { cout << n << endl; });
	for_each(x, x + 5, closure_object());
	return 0;
}
#endif

#if 0
#include <iostream>
#include <algorithm>
using namespace std;

inline void show(int n) { cout << n << endl; }
struct ShowFunctor
{
	inline void operator()(int n) const { cout << n << endl; }
};
int main()
{
	int x[] = { 1,2,3,4,5 };

	for_each(x, x + 5, show);

	for_each(x, x + 5, ShowFunctor());

	for_each(x, x + 5, [](int n){ cout << n << endl; } ); 
	return 0;
}
#endif
