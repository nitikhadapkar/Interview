#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char *ch = "ABC", *ch1 = "XYZ", *intr = "AXBDCYZ";

	int len1 = strlen(ch), len2 = strlen(ch1), len3 = strlen(intr);

	int i,j,k;
	for(i=0,j=0,k=0;k<len3;k++)
	{
		cout<<intr[k]<<endl;
		if(ch[i] == intr[k])
		{
			cout<<ch[i]<<" "<<intr[k]<<endl;
			i++;
		}
		else if(ch1[j] == intr[k])
		{
			cout<<ch[j]<<" "<<intr[k]<<endl;
			j++;
		}
		else
		{
			cout<<"NOT Interleaved"<<endl;
			break;
		}
	}
	cout<<"Interleaved..  "<<endl;
	return 0;
}
