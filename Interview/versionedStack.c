#include <stdio.h>

#define	TRUE	1
#define	FALSE	0
#define SIZE	10

int stack[SIZE];
int stkPtr = -1;

int pop();
void push(int n);
int isEmpty();
int isFull();

int main()
{
	return 0;
}

void push(int n)
{
	if(isFull())
	{
		printf("Stack Overflow!!\n");
	}
	else
	{
		stkPtr++;
		stack[stkPtr] = n;
	}
}

int pop()
{
	int num;
	if(isEmpty())
	{
		printf("Stack Underflow\n");
		return -10000;
	}
	else
	{
		num = stack[stkPtr];
		stkPtr--;
		return num;
	}
}
int isEmpty()
{
	if(stkPtr == -1)
		return TRUE;
	else
		return FALSE;
}

int isFull()
{
	if(stkPtr == SIZE-1)
		return TRUE;
	else
		return FALSE;
}
