/*
Find the first occurance of a number in a sorted array.
*/

#include <iostream>

using namespace std;

int binary_search(int *arr, int first, int last, int num);

int main()
{
	int arr[] = {1,1,2,3,3,4,4,4,4,4,6,6,6,6,7};
//	int arr[] = {4,4,4,4,4};
	int length = 15, first = 0, last = length - 1;
	cout<<binary_search(arr, first, last, 6)<<endl;
	return 0;
}
int binary_search(int *arr, int first, int last, int num)
{
	int mid = (first+last)/2;

	while((arr[mid]!=num) && (first<last))
	{
		if(arr[mid]>num)
		{
			last = mid-1;
		}
		else
		{
			first = mid+1;
		}
		mid = (first+last)/2;
	}
	if(arr[mid-1] == num)
	{
		return binary_search(arr, first, mid-1, num);
	}

	else
		return mid;

}
