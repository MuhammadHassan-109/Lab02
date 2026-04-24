#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main()
{
	BinaryTree B;
	NODEPTR root = B.maketree(50);
	root->left = B.maketree(30);
	root->right = B.maketree(80);
	root->right->right = B.maketree(90);
	root->right->left = B.maketree(70);
	root->left->left = B.maketree(20);
	root->left->right = B.maketree(40);

	cout << "Pre-Order Traversal : ";
	B.preorder(root);
	cout << "\n";

	cout << "Post-Order Traversal : ";
	B.postorder(root);
	cout << "\n";

	cout << "In-Order Traversal : ";
	B.inorder(root);
	cout << "\n";

	return 0;

}