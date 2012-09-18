/*
Given an array of integers, the function should return an array,
with each position having the product of all other numbers than itself.
Corner cases have to be handled
*/

#include <iostream>

using namespace std;

int* product(int *arr, int length);
int main()
{
//	int arr[] = {1,2,-3,0,0};
	int arr[] = {1,2,3,4,5};
	int i,length = 5;

	int *result = product(arr, length);

	cout<<"Product array: "<<endl;
	for(i=0;i<length;i++)
		cout<<result[i]<<" ";

	cout<<"\n";
	delete(result);
	return 0;
}
int* product(int *arr, int length)
{
	int *result = new int[(sizeof(int) * length)];
	int i, prod = 1, zero_flag = 0;

	for(i=0;i<length;i++)
	{
		if(arr[i] == 0)
			zero_flag = 1;
		else
			prod = prod * arr[i];
	}

	cout<<"TOTAL PRODUCT: "<<prod<<endl;
	for(i=0;i<length;i++)
	{
		if(!zero_flag)
			result[i] = prod/arr[i];

		else
		{
			result[i] = arr[i]?0:prod;
		}
	}

	return result;
}
