#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node
{
	int data;
	Node *left_ptr;
	Node *right_ptr;
};

Node* bsTree(int *arr, int size);
void insert_into_bst(Node **n, int data);
void preorder(Node *n);
void inorder(Node *n);
void postorder(Node *n);
int getParent(Node *node, int data);
int least_common_ancestor(Node *node, int a, int b);

int main()
{
	int arr[]={5,3,7,6,8,2,4};
	Node *root = bsTree(arr,7);
//	cout<<getParent(root,5)<<endl;
	cout<<least_common_ancestor(root,2,4)<<endl;
//	postorder(root); cout<<endl;
//	inorder(root); cout<<endl;
//	preorder(root); cout<<endl;
	return 0;
}
int least_common_ancestor(Node *node, int a, int b)
{
	int parent;
	if(node->data>a && node->data>b)
	{
		parent = least_common_ancestor(node->left_ptr, a, b);
		cout<<node->data<<" ";
		return parent;
	}
	else if(node->data<a && node->data<b)
	{
		parent = least_common_ancestor(node->right_ptr, a, b);
		cout<<node->data<<" ";
		return parent;
	}
	else
		return node->data;
}
Node* bsTree(int *arr, int size)
{
	Node *root = NULL;
	int i;
	for(i=0;i<size;i++)
	{
		insert_into_bst(&root,arr[i]);
	}
	return root;
}
int getParent(Node *node, int data)
{
	//corner case.. if the parent of root is being searched.
	if(node->data == data)
	{
		return -1;
	}
	if(node->data>data)
	{
		if(node->left_ptr->data == data)
		{
			return node->data;
		}
		else
			return getParent(node->left_ptr, data);
	}
	else 
	{
		if(node->right_ptr->data == data)
		{
			return node->data;
		}
		else
			return getParent(node->right_ptr, data);
	}
			
}
void insert_into_bst(Node **n, int data)
{
	//corner case 
	if((*n) == NULL)
	{
		*n = (Node*) malloc(sizeof(Node));
		(*n)->data = data;
		return;
	}

	if((*n)->data>data)
	{
		insert_into_bst(&((*n)->left_ptr),data);
	}
	else
	{
		insert_into_bst(&((*n)->right_ptr),data);
	}
}
void postorder(Node *node)
{
	if(node)
	{
		postorder(node->left_ptr);
		postorder(node->right_ptr);
		cout<<node->data<<" ";
	}
}
void inorder(Node *node)
{
	if(node)
	{
		inorder(node->left_ptr);
		cout<<node->data<<" ";
		inorder(node->right_ptr);
	}
}
void preorder(Node *node)
{
	if(node)
	{
		cout<<node->data<<" ";
		preorder(node->left_ptr);
		preorder(node->right_ptr);
	}
}
