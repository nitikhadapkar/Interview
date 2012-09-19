/*
Given a linked list that contains 0,1 and 2.
Sort this linked such that it contains 0s first, then 1s and then 2s in O(n) time. 
Remember its a linked list not an array.
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
void sort(Node **head);

int main()
{
	Node *head;

	//{0->1->0->2->1->1->2->0}

	insert(&head, 0);
	insert(&head, 1);
	insert(&head, 0);
	insert(&head, 2);
	insert(&head, 1);
	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 2);
	insert(&head, 0);
//	insert(&head, -1);

	display(head);

	sort(&head);
	display(head);
	deleteLL(&head);
	return 0;
}

void sort(Node **head)
{
	Node *start0 = NULL, *start1 = NULL, *start2 = NULL, *cur_ptr = NULL;
	Node *end0 = NULL, *end1 = NULL, *temp = NULL, *end2 = NULL;

	cur_ptr = *head;

	while(cur_ptr != NULL)
	{
		printf("%d\n", cur_ptr->data);
		temp = cur_ptr->next;
		if(cur_ptr->data == 0)
		{
			if(start0 == NULL)
			{
				start0 = cur_ptr;
				end0 = start0;
			}
			else
			{
				end0->next = cur_ptr;
				end0 = end0->next;
				end0->next = NULL;
			}
		}
		else if(cur_ptr->data == 1)
		{
			if(start1 == NULL)
			{
				start1 = cur_ptr;
				end1 = start1;
			}
			else
			{
				end1->next = cur_ptr;
				end1 = end1->next;
				end1->next = NULL;
			}
		}
		else if(cur_ptr->data == 2)
		{
			if(start2 == NULL)
			{
				start2 = cur_ptr;
				end2 = start2;
			}
			else
			{
				end2->next = cur_ptr;
				end2 = end2->next;
				end2->next = NULL;
			}
		}
		cur_ptr = temp;
	}

	*head = (start0?start0:start1)?(start0?start0:start1):start2;
	if(start0 != NULL)
		end0->next = start1?start1:start2;

	if(start1 != NULL)
		end1->next = start2;
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
