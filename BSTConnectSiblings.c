/*
Given a tree, link all the siblings from right to left.
*/

#include <stdio.h>

typedef struct tn
{
	int data;
	struct tn *left;
	struct tn *right;
	struct tn *next;
}TreeNode;


void connect_siblings(TreeNode *n);
void call_display(TreeNode *n);
void display_connections(TreeNode *n);

void insert_into_bst(TreeNode **n, int data);
void delete_tree(TreeNode **n);
void inorder(TreeNode *node);

int main()
{
	int arr[] = {4,2,6,7,5,3,1}, i;
	TreeNode *root = NULL;

	for(i=0;i<7;i++)
		insert_into_bst(&root, arr[i]);

	inorder(root);
	printf("\n");

	printf("CONNECTIONS\n");
	connect_siblings(root);
	call_display(root);
	delete_tree(&root);

	return 0;
}
void connect_siblings(TreeNode *n)
{
	if(n == NULL)
		return;

	if(n->left != NULL)
		(n->left)->next = n->right;

	if(n->right != NULL)
	{
		if(n->next)
			(n->right)->next = (n->next)->left?(n->next)->left:(n->next)->right;
		else
			(n->right)->next = NULL;
	}

	connect_siblings(n->left);
	connect_siblings(n->right);
}
void call_display(TreeNode *n)
{
	if(n->left != NULL)
	{
		display_connections(n->left);
		call_display(n->left);
	}
	else if(n->right != NULL)
	{
		display_connections(n->right);
		call_display(n->right);
	}
	else if(n->next != NULL)
	{
		call_display(n->next);
	}
	else
		return;
}
void display_connections(TreeNode *n)
{
	while(n != NULL)
	{
		printf("%d ",n->data);
		n = n->next;
	}
	printf("NULL\n");
}
void insert_into_bst(TreeNode **n, int data)
{
	if((*n) == NULL)
	{
		*n = (TreeNode*) malloc(sizeof(TreeNode));
		(*n)->data = data;
		(*n)->left = NULL;
		(*n)->right = NULL;
		(*n)->next = NULL;
		return;
	}

	if((*n)->data>data)
	{
		insert_into_bst(&((*n)->left),data);
	}
	else
	{
		insert_into_bst(&((*n)->right),data);
	}
}
void delete_tree(TreeNode **n)
{
	if((*n) == NULL)
		return;

	if((*n)->left != NULL)
		delete_tree(&((*n)->left));
	
	if((*n)->right != NULL)
		delete_tree(&((*n)->right));

	free(*n);
	*n = NULL;
}
void inorder(TreeNode *node)
{
	if(node)
	{
		inorder(node->left);
		printf("%d ", node->data);
		inorder(node->right);
	}
}
