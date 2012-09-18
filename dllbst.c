#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
	int data;
	struct n *next;
	struct n *prev;
}Node;

typedef struct tn
{
	int data;
	struct tn *left;
	struct tn *right;
}TreeNode;

void getDLL(Node **);
void generateBST(Node *start, Node *last, TreeNode **tnode);
int countNode(Node *start, Node *last);
void displayDLL(Node *);
Node* getNode(Node *start, int n);

int main()
{
	Node *head, *last;
	TreeNode *root;

	getDLL(&head);
	displayDLL(head);

	last = head;
	while(last->next != NULL)
		last = last->next;

	generateBST(head, last, &root);
	return 0;
}

int countNode(Node *start, Node *last)
{
	int count = 0;
	Node *node = start;
	while(node != last)
	{
		node = node->next;
		count++;
	}
	return count;
}

Node* getNode(Node *start, int n)
{
	int i=0;
	while(i++<n)
		start = start->next;

	return start;
}

void generateBST(Node *start, Node *last, TreeNode **tnode)
{
	printf("generate BST\n");
	int length = countNode(start,last), mid;
	mid = length/2;

	Node *n = getNode(start, mid);
	printf("MID: %d\n",n->data);
	*tnode = (TreeNode *) malloc(sizeof(TreeNode));
	(*tnode)->data = n->data;

	generateBST(start, n->prev, &(*tnode)->left);
	generateBST(n->next,last,&(*tnode)->right);
}

void getDLL(Node **head)
{
	printf("getDLL\n");
	if(*head == NULL)
	{
	printf("head is null\n");
		*head = (Node *) malloc(sizeof(Node));
		(*head)->data = 1;
	}
	
	Node **nodeNext = &((*head)->next);
	Node **nodePrev = head;

	int i;

	for(i=2;i<=10;i++)
	{
		*nodeNext = (Node *) malloc(sizeof(Node));
		(*nodeNext)->data = i;
		(*nodeNext)->prev = *nodePrev;
		nodePrev = nodeNext;
		nodeNext = &((*nodeNext)->next);
	}
}

void displayDLL(Node *node)
{
	while(node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}
