#include <stdio.h>

typedef struct x{
	int data;
	struct x *next;
}Node;

void insert(Node **node, int data);
void display(Node *node);
void delete_specific_node(Node **, int data);

int main()
{
	Node *head;

	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,2);
	insert(&head,3);
	display(head);

	delete_specific_node(&head, 1);
	display(head);

	return 0;
}

void delete_specific_node(Node **node, int data)
{
	Node *nde, *prev;
	while((*node) != NULL)
	{
		printf("Node: %d\n",(*node)->data);
		if((*node)->data == data)
		{
			(*node) = (*node)->next;
		}
		else
			break;
	}
	if(*node == NULL)
		return;

	prev = *node;
	nde = (*node)->next;
	while(nde != NULL)
	{
		printf("Node: %d\n", nde->data);
		if(nde->data == data)
		{
			prev->next = nde->next;
			free(nde);
			nde = NULL;
		}
		else
		{
			prev = nde;
		}
		nde = prev->next;
	}
}
void insert(Node **head, int data)
{
	Node *node;
	if(*head == NULL)
	{
		*head = (Node *) malloc(sizeof(Node));
		(*head)->data = data;
		(*head)->next = *head;
		return;
	}

	node = *head;
	while(node->next != NULL)
		node = node->next;

	if(node->next == NULL)
	{
		node->next = (Node *) malloc(sizeof(Node));
		node = node->next;
		node->data = data;
	}
}

void display(Node *node)
{
	while(node != NULL)
	{
		printf("%d --> ", node->data);
		node = node->next;
	}
	printf("NULL\n");
}
