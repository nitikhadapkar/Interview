#include <iostream>

using namespace std;

int main()
{
	int a[] = {4,71,1,6,8,9,2,10};
	int size = 8;
	int i,j, smallest,mi,mj,max;

	smallest = 0;
	mi = 0; mj = 0; max = 0;	

	for(j=1;j<size;j++)
	{
		if(a[j]<a[smallest])
			smallest = j;
		else
		{
			cout<<"mi: "<<a[smallest]<<" mj: "<<a[j]<<endl;
			if(max < (a[j] - a[smallest]))
			{
				max = a[j] - a[smallest];
				mi = smallest;
				mj = j;
			}
		}
	}

	cout<<"Max: "<<max<<endl;
	cout<<"mi: "<<a[mi]<<" mj: "<<a[mj]<<endl;

	return 0;
}
