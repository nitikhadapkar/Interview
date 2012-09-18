#include <iostream>

using namespace std;

void rotate_array(char a[], int f, int r, int l);
void swap(char *a, char *b);
void display(char a[], int len);
int main()
{
	char a[] = {'1','2','3','a','b','c','d'};
	//char a[] = {'1','2','3','a','b','c'};
	//char a[] = {'1','2','3','a','b'};
	int length = 7, rotate = 3;

	rotate_array(a,0,rotate,length-1);
	display(a,length);
//	int f,l = length-1,rotate,i;

/*	for(f=0,i=r;i<l;i++)
	{
		swap(&a[f],&a[i]);
		f++;
	}
*/
	return 0;
}
void rotate_array(char a[], int f, int r, int l)
{
	int i;

	cout<<"f "<<f<<" l "<<l<<" r "<<r<<endl;

	if(f == l)
	{
		cout<<"f "<<f<<" and l "<<l<<endl;
		return;
	}

	for(i=r;i<=l;i++)
	{
		swap(&a[f],&a[i]);
	display(a, l+1);
		f++;
	}
	if(f<r)
		rotate_array(a,f,r,l);
	else
	{
		cout<<"HERE"<<endl;
		r = (f+l)/2;
		rotate_array(a,f,r,l);
	}
}
void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
void display(char a[], int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
