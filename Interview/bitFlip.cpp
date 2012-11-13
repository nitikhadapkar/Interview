/* Flip the nth bit of the number m
*/

#include <iostream>

using namespace std;

int numToBin(int a[], int num);
int binToNum(int a[], int size);

int main()
{
	int a[10], size;
	int m=8, n=4;

	size = numToBin(a, m);
	a[n-1] = a[n-1]^1;

	cout<<"Number: "<<binToNum(a,size)<<endl;

	return 0;
}

int numToBin(int a[], int num)
{
	int i=0;

	while(num!=0)
	{
		a[i] = num%2;
		i++;
		num = num/2;
	}

	return i;
}

int binToNum(int a[], int size)
{
	int i, pow2=1, num=0;

	for(i=0;i<size;i++)
	{
		num = num + a[i]*pow2;
		pow2 = pow2 * 2;
	}
	return num;
}
