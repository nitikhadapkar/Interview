/*
	Iterative Preorder of a tree
	Preorder: 10 8 3 5 9 2
	Inorder: 3 8 5 10 9 2
	Postorder: 3 5 8 2 9 10
*/

#include <iostream>
#include <stdlib.h>
#include <queue>
#include <stack>

using namespace std;

typedef struct TreeNode {
	int data;
	TreeNode *left;
	TreeNode *right;
};

TreeNode* createTree()
{
	TreeNode *root = (TreeNode*) malloc(sizeof(TreeNode));
	root->data = 10;
	root->left = (TreeNode*) malloc(sizeof(TreeNode));
	root->left->data = 8;
	root->right = (TreeNode*) malloc(sizeof(TreeNode));
	root->right->data = 9;
	root->left->left = (TreeNode*) malloc(sizeof(TreeNode));
	root->left->left->data = 3;
	root->left->right = (TreeNode*) malloc(sizeof(TreeNode));
	root->left->right->data = 5;
	root->right->right = (TreeNode*) malloc(sizeof(TreeNode));
	root->right->right->data = 2;

	return root;
}

void preorder_traversal(TreeNode *root)
{
	//Root, Left, Right
	TreeNode *curr;
	stack<TreeNode*> mystack;

	if(root == NULL)
		return;

	mystack.push(root);

	cout<<"Preorder: ";
	while(!mystack.empty())
	{
		curr = mystack.top();
		mystack.pop();

		if(curr->right)
			mystack.push(curr->right);
		if(curr->left)
			mystack.push(curr->left);

		cout<<curr->data<<" ";
	}
	cout<<"\n";
}
void inorder_traversal(TreeNode *root)
{
	// Left, Root, Right
	TreeNode *curr;
	stack<TreeNode*> mystack;

	if(root == NULL)
	{	
		return;
	}

	mystack.push(root);

	cout<<"Inorder: ";
	while(!mystack.empty())
	{
		curr = mystack.top();
		mystack.pop();

		if(curr->right)
		{
			mystack.push(curr->right);
		}
		mystack.push(curr);

		if(curr->left)
		{
			mystack.push(curr->left);
		}
		else
		{
			mystack.pop();
			cout<<curr->data<<" ";
			if(!mystack.empty())
			{
				curr = mystack.top();
				mystack.pop();
				cout<<curr->data<<" ";
			}
		}
	}
	cout<<"\n";
}
void deleteTree(TreeNode *root)
{
	//iterative way
	TreeNode *current;
	queue<TreeNode*> myqueue;

	if(root == NULL)
		return;

	myqueue.push(root);

	while(!myqueue.empty())
	{
		current = myqueue.front();
		myqueue.pop();
		if(current->left)
			myqueue.push(current->left);
		if(current->right)
			myqueue.push(current->right);

		delete current;
	}
}
int main()
{
	TreeNode *root = createTree();

	preorder_traversal(root);
	inorder_traversal(root);

	deleteTree(root);
	return 0;
}
