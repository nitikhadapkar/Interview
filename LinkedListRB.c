//Linked List
/*
Given 2 linked lists sorted in ascending order, write a function that will merge these lists
into a single sorted list without copying the list contents.
You can assume a node structure of the form:

struct Node {
int value;
Node *next;
}; 

*/

#include <stdio.h>

struct Node {

	int value;
	struct Node *next;
};

void insert(struct Node **n, int value);
void mergeLL(struct Node **head1, struct Node **head2);
void deleteLL(struct Node *n);
void display(struct Node *n);

int main()
{
	struct Node *LL1 = NULL, *LL2 = NULL;
	int i;

	for(i=0;i<10;i++)
	{
		if((i+1)<6)
			insert(&LL1, (i+1));
		else
			insert(&LL2, (i+1));
	}
	insert(&LL2,12);
	insert(&LL1,13);
	insert(&LL2,14);

	printf("The sorted linked lists are: \n");
	printf("LL1: "); display(LL1);
	printf("LL2: "); display(LL2);

	mergeLL(&LL1, &LL2);
	printf("The merged list: ");
	display(LL1);

	deleteLL(LL1);
}
//inserts a node into the linked list
void insert(struct Node **n, int value)
{
	while(*n != NULL)
		n = &(*n)->next;
	if(*n == NULL)
	{
		printf("INHERE\n");
		*n = (struct Node*) malloc(sizeof(struct Node));
		(*n)->value = value;
		(*n)->next = NULL;
	}
}

// merges 2 linked list together
void mergeLL(struct Node **head1, struct Node **head2)
{
	struct Node *ll1, *ll2;
	struct Node *prev;

	if(*head2 == NULL)
		return;

	if(*head1 == NULL)
	{
		*head1 = *head2;
		return;
	}

	ll1 = *head1; ll2 = *head2;
	prev = ll1;

	while( (ll1 != NULL) && (ll2 != NULL))
	{
		//both the lls arent null
		if(ll1->value > ll2->value)
		{
			//if the head of first list is 
			//greater than the head of the second
			if(prev == ll1)
			{
				(*head1) = ll2;
				ll2 = ll2->next;
				prev = *head1;
				prev->next = ll1;
			}
			else
			{
				prev->next = ll2;
				prev = ll2;
				ll2 = ll2->next;
				prev->next = ll1;
			}
		}
		else
		{
			prev = ll1;
			ll1 = ll1->next;
		}
	}

	if(ll1 == NULL)
	{
		prev->next = ll2;
	}
	
}

//delete the nodes of the linked list
void deleteLL(struct Node *n)
{
	if(n==NULL)
		return;
	deleteLL(n->next);
	free(n);
}

//displays a linked list
void display(struct Node *n)
{
	while(n != NULL)
	{
		printf("%d --> ", n->value);
		n = n->next;
	}
	printf("NULL\n");
}
