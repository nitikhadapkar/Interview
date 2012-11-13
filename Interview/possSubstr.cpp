#include <iostream>

using namespace std;

void generateSubstring(char a[], int len);

int main()
{
	char a[] = {'a','b','c'};
	int len = 3;

	generateSubstring(a,len);

	return 0;
}

void generateSubstring(char a[], int len)
{
	int i, size = 1, n, j = 0;

	for(i=0;i<len;i++)
		size = size*2;

	for(i=0;i<size;i++)
	{
		n = i; j = 0;
		while(n!=0)
		{
			if(n%2 == 1)
				cout<<a[j];
			j++;
			n = n/2;
		}
		cout<<endl;
	}	
}
