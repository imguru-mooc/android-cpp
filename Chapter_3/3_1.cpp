#if 1
#include <stdio.h>
#include "List.h"
using namespace android;

template <class InputIt, class T>
InputIt find(InputIt first, InputIt last, const T& value) {
	for (; first != last; ++first) {
		if (*first == value) {
			return first;
		}
	}
	return last;
}

int main()
{
	List<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);

	List<int>::iterator result;
	result = find( l1.begin(), l1.end(), 3 );
	printf("result=%d\n", *result );

	return 0;
}
#endif
#if 0
#include <stdio.h>
#include "List.h"
using namespace android;

int main()
{
	List<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);

	List<int>::iterator i;
	for(i=l1.begin(); i!=l1.end(); i++)
		printf("%d\n", *i);
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include "List.h"
using namespace android;

int main()
{
	List<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	printf("size()=%lu\n", l1.size());
	return 0;
}
#endif
