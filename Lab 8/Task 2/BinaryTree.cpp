#include "BinaryTree.h"
#include <iostream>
using namespace std;

int BinaryTree::height = -1;
int BinaryTree::totalNodes = 0;
int BinaryTree::leaves = 0;

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
		cout << p->info << "   ";
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

void BinaryTree::Totalnodes(NODEPTR p)
{
	//I am using pre-order traversal any of the three can be used.
	if (p != NULL)
	{
		totalNodes++;
		Totalnodes(p->left);
		Totalnodes(p->right);
	}
}

void BinaryTree::FindHeight(NODEPTR p)
{
    FindHeightHelper(p, 0);
}

void BinaryTree::FindHeightHelper(NODEPTR p, int currentDepth)
{
    if (p == NULL)
	{
		return;
	}

    
    if (currentDepth > height)
	{
		height = currentDepth;
	}

    FindHeightHelper(p->left,  currentDepth + 1);
    FindHeightHelper(p->right, currentDepth + 1);
}


void BinaryTree::countLeaf(NODEPTR p)
{
	if (p != NULL)
	{
		if (p->left == NULL && p->right == NULL)
		{
			leaves++;
			cout << p->info <<"    ";
		}
		else
		{
			countLeaf(p->left);
			countLeaf(p->right);
		}
	}
	
}