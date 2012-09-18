#include <iostream>

using namespace std;

void grayToBin(int *x, int *y, int index, int l);
void binToGray(int *x, int *y, int index, int l);

int main()
{
	int gray[] = {1,1,1,1}, binAns[4];
	int bin[] = {0,1,0,1}, grayAns[4];
	int length = 4;

	grayToBin(binAns, gray, length-1, 0);

	cout<<"GRAY TO BIN: ";
	for(int i=length-1;i>=0;i--)
		cout<<binAns[i];
	cout<<endl;

	binToGray(grayAns, bin, length-1, 0);
	cout<<"BIN to GRAY: ";
	for(int i=length-1;i>=0;i--)
		cout<<grayAns[i];
	cout<<endl;
	
	return 0;
}
void binToGray(int *x, int *y, int index, int l)
{
	if(index == -1)
		return;
	else
	{
		x[index] = y[index]^l;
		l = y[index];
		index--;
		binToGray(x,y,index,l);
	}
}
void grayToBin(int *x, int *y, int index, int l)
{
	if(index == -1)
		return;

	else
	{
		x[index] = y[index] ^ l;
		l = x[index];
		index--;
		grayToBin(x, y, index, l); 
	}
}
