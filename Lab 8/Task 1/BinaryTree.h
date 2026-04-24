#pragma once


struct node
{
	int info;
	node* left;
	node* right;
};
typedef node* NODEPTR;

class BinaryTree
{
public:
	NODEPTR maketree(int x);
	void setleft(NODEPTR p, int x);
	void setright(NODEPTR p, int x);
	void preorder(NODEPTR p);
	void inorder(NODEPTR p);
	void postorder(NODEPTR p);
};
