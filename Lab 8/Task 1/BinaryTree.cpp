#include "BinaryTree.h"
#include <iostream>
using namespace std;


NODEPTR BinaryTree::maketree(int x)
{
	NODEPTR p = new node;
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void BinaryTree::setleft(NODEPTR p, int x)
{
	if (p == NULL)
	{
		cout << "\nVoid Insertion";
	}
	else if (p->left != NULL)
	{
		cout << "\nleft child already exists...!";
	}
	else
	{
		p->left = maketree(x);
	}
}

void BinaryTree::setright(NODEPTR p, int x)
{
	if (p == NULL)
	{
		cout << "\nVoid Insertion";
	}
	else if (p->right != NULL)
	{
		cout << "\nright child already exists...!";
	}
	else
	{
		p->right = maketree(x);
	}
}

void BinaryTree::preorder(NODEPTR p)
{
	if (p != NULL)
	{
		cout << p->info<<"   ";
		preorder(p->left);
		preorder(p->right);
	}
}

void BinaryTree::inorder(NODEPTR p)
{
	if (p != NULL)
	{
		inorder(p->left);
		cout << p->info << "   ";
		inorder(p->right);
	}
}

//left-right-root
void BinaryTree::postorder(NODEPTR p)
{
	if (p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout << p->info << "   ";
	}
}