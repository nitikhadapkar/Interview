#include <iostream>

using namespace std;

int main()
{
	int i, j, k, arr[] = {1,2,5,6,3,2,4};
	int length = 7, goal = 9, goal_temp = 0;

	int solution_arr[5][goal+1][length+1];

	for(i=0;i<length;i++)
	{
		solution_arr[0][0][i+1] = arr[i];
	}
	for(i=0;i<goal;i++)
	{
		solution_arr[0][i+1][0] = i+1;
	}
	for(i=0;i<4;i++)
	{
		solution_arr[i+1][0][0] = i+1;
	}


	for(i=1;i<=4;i++)
	{
		for(j=1;j<=goal;j++)
		{
			for(k=1;k<=length;k++)
			{
			}
		}
	}

	return 0;
}
