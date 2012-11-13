/*
A tic tac toe game
*/

#include <stdio.h>

#define INIT		-1
#define	X		1
#define	O 		0
#define INCOMPLETE	-1
#define COMPLETE	2
#define FILLED		1
#define NOT_FILLED	0

int make_move(int b[][], int i, int j, int value);
int check_board(int b[][]);
void display_board(int b[][]);

int main()
{
	int i,j, board[3][3], winner, flag=1;

	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			board[i][j] = INIT;

	do
	{
		display_board(board);

		printf("Enter co-ordinates: ");
		scanf("%d",&i);
		scanf("%d",&j);

		make_move(board, i-1,j-1,flag);

		if(flag)
			flag = O;
		else
			flag = X;		
	}while((winner = check_board(board)) != COMPLETE);


	if(winner == X)
		printf("Player 1 wins\n");
	else if(winner == O)
		printf("Player 2 wins\n");
	else
		printf("No winner\n");
	return 0;
}

void display_board(int board[][])
{
	int i, j;

	printf("%d |\n",board[0][0]);
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(i == 0)
				printf("%d | ",j);
			else if(j == 0)
				printf("%d | ",i);
			else if(i!=0 && j!=0)
			{
				if(board[i-1][j-1] == INIT)
					printf("  | ");
				
				else if(board[i-1][j-1] == X)
					printf("X  | ");
				else if(board[i-1][j-1] == O)
					printf("O  | ");
			}
		}
		printf("\n\n");
	}
}

int make_move(int board[][], int i, int j, int value)
{
	if(board[i][j] != INIT)
		return -1;


	board[i][j] = value;
	return 0;
} 
int check_board(int board[][])
{
	int i, j;

	if(board[1][1] != -1)
	{
		//4 possibilities
		if((board[1][0] == board[1][1]) && (board[1][2] == board[1][1]))
			return board[1][1];
		if((board[0][1] == board[1][1]) && (board[1][2] == board[2][1]))
			return board[1][1];
		if((board[0][0] == board[1][1]) && (board[2][2] == board[1][1]))
			return board[1][1];
		if((board[0][2] == board[1][1]) && (board[2][0] == board[1][1]))
			return board[1][1];
	}

	if(board[0][0] !=-1)
	{
		//2 possibilities

		if((board[0][0] == board[0][1]) && (board[0][2] == board[0][0]))
			return board[0][0];
		if((board[0][0] == board[1][0]) && (board[2][0] == board[0][0]))
			return board[0][0];

	}

	if(board[2][2] !=-1)
	{
		//2 possibilities

		if((board[2][0] == board[2][2]) && (board[2][2] == board[2][1]))
			return board[2][2];
		if((board[2][2] == board[0][2]) && (board[2][2] == board[1][2]))
			return board[2][2];

	}

	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(board[i][j] == INIT)
				return INCOMPLETE;

	return COMPLETE;
}
