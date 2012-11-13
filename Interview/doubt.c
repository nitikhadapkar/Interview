#include <stdio.h>
//one min, checking
int display(int *board[])
{
	int i,j;

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%d ",board[i][j]);

		printf("\n");
	}
}

int main()
{
	int i,j, board[3][3];

	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			board[i][j] = -1;

	display(board);

	return 0;
}
