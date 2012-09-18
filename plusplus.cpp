#include <iostream>

using namespace std;

//incrementing operation

void plusplus(int a[], int length);
int main()
{
	int a[] = {8,9,9,9};
	plusplus(a,4);

	return 0;
}

void plusplus(int a[], int length)
{
	int b[length+1], i, j, carry = 0;

	carry = 1;
	for(i=length-1,j=length;i>=0;i--,j--)
	{
		a[i] = a[i] + carry;
		b[j] = a[i]%10;
		cout<<"b[j]: "<<b[j];
		carry = a[i]/10;
		cout<<" carry: "<<carry<<endl;
	}

	b[0] = carry;

	cout<<"Solution is: ";
	for(i=0;i<=length;i++)
		cout<<b[i];

	cout<<endl;

}
