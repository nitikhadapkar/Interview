/*
given linked list a->b->c->d->e convert to
b->a->d->c->e without creating new node.
*/

#include <stdio.h>

typedef struct n
{
	int data;
	struct n *next;
}Node;

void insert(Node **, int data);
void deleteLL(Node **n);
void display(Node *n);
void reverse(Node **);

int main()
{
	return 0;
}

void insert(Node **n, int data)
{
	while(*n != NULL)
		n = &(*n)->next;
	if(*n == NULL)
	{
		*n = (Node*) malloc(sizeof(Node));
		(*n)->data = data;
		(*n)->next = NULL;
	}
}
void deleteLL(Node **n)
{
	if(*n==NULL)
		return;
	deleteLL(&(*n)->next);
	free(*n);
	*n = NULL;
}
void display(Node *n)
{
	while(n != NULL)
	{
		printf("%d --> ", n->data);
		n = n->next;
	}
	printf("NULL\n");
}
