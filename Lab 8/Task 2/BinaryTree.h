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
	static int leaves;
	static int height;
	static int totalNodes;

	NODEPTR maketree(int x);
	void setleft(NODEPTR p, int x);
	void setright(NODEPTR p, int x);
	void preorder(NODEPTR p);
	void inorder(NODEPTR p);
	void postorder(NODEPTR p);
	void Totalnodes(NODEPTR p);
	void FindHeight(NODEPTR p);
	void FindHeightHelper(NODEPTR p, int currentDepth);
	void countLeaf(NODEPTR p);
};

