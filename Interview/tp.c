// to check stuff of C

#include <stdio.h>

int main()
{
	int len =10;

	int arr[len], i;

	for(i=0;i<10;i++)
	{
		arr[i] = 10;
	}

	printf("SIZE: %d\n", sizeof(arr[0]));

	int *p = -1;
	printf("pointer: %d\n",p);
	++p;
	printf("pointer: %d\n",p);

	return 0;
}
