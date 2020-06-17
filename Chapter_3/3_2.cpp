
#if 1
#include <stdio.h>
#include <string>
#include <iostream>
#include "KeyedVector.h"
using namespace android;
using namespace std;

int main()
{
	KeyedVector<int, string> v1;
	v1.add(4, "Kim");
	v1.add(3, "Lee");
	v1.add(2, "Park");
	v1.add(1, "Choi");

	int i;
	for(i=0; i<v1.size(); i++ )
		cout << v1[i] << endl;

	cout << "----------" << endl;
	cout << v1.valueFor(4) << endl;
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include "SortedVector.h"
using namespace android;

int main()
{
	SortedVector<int> v1;
	v1.add(4);
	v1.add(3);
	v1.add(2);
	v1.add(1);

	int i;
	for(i=0; i<v1.size(); i++ )
		printf("%d\n", v1[i]);
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include "Vector.h"
using namespace android;

int main()
{
	Vector<int> v1;
	v1.add(1);
	v1.add(2);
	v1.add(3);
	v1.add(4);

	v1.insertAt(5,1);
	int i;
	for(i=0; i<v1.size(); i++ )
		printf("%d\n", v1[i]);
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include "Vector.h"
using namespace android;

int main()
{
	Vector<int> v1;
	v1.add(1);
	v1.add(2);
	v1.add(3);
	v1.add(4);
	Vector<int>::iterator iter;
	for(iter=v1.begin(); iter!=v1.end(); iter++ )
		printf("%d\n", *iter);

	int i;
	for(i=0; i<v1.size(); i++ )
		printf("%d\n", v1[i]);

	v1.replaceAt(10,0);
	for(i=0; i<v1.size(); i++ )
		printf("%d\n", v1[i]);
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include "Vector.h"
using namespace android;

int main()
{
	Vector<int> v1;
	Vector<int> v2;
	v1.setCapacity(8);
	v1.add(1);
	v1.add(2);
	v1.add(3);
	printf("size()=%lu\n", v1.size());
	v2 = v1;
	printf("size()=%lu\n", v2.size());
	v1.add(4);
	printf("size()=%lu\n", v1.size());
	printf("size()=%lu\n", v2.size());
	v2.add(5);
	printf("size()=%lu\n", v1.size());
	printf("size()=%lu\n", v2.size());
	printf("v1[3]=%d\n", v1[3]);
	printf("v2[3]=%d\n", v2[3]);

	return 0;
}
#endif
