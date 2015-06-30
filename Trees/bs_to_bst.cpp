/**
	Converting a binary tree to binary search tree
	1. In the Binary tree, store the value in an array for a inorder traversal
	2. Sort that array
	3. Traverse the tree again inorder and replace the value from the array
**/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

std::vector<int> array;
class Tree {

public:
	
	Tree(int v) : left(NULL),right(NULL),value(v) {}

	Tree *createBinaryTree(Tree *node)
	{
		
			
			node =new Tree(1);
			node->left = new Tree(2);
			node->right = new Tree(3);
			node->left->left = new Tree(4);
			node->left->right = new Tree(5);
			node->right->left = new Tree(6);
			node->right->right = new Tree(7);

			return node;

	}

	void inorder(Tree *n)
	{
		if( n != NULL )
		{
			
			inorder(n->left);
			cout << n->value << " ";
			array.push_back(n->value);
			inorder(n->right);
		}
	}

	Tree *convertToBST(Tree *node)
	{
		sort(array.begin(),array.end());
		int i = 0;
		inorder_2(&node,&i);

		return node;
	}

	void inorder_2(Tree **node, int *index)
	{

		if( (*node) != NULL )
		{
			inorder_2(&((*node)->left), index);

			(*node)->value = array[*index];
			//cout << (*node)->value << " ";
			(*index)++;

			inorder_2(&((*node)->right),index);
		}
	}


private:
	Tree *left;
	Tree *right;
	int value;

};

int main()
{
	Tree *root = NULL;

	root = root->createBinaryTree(root);
	cout << "\n Before converting to BST. Inorder Traversal \n";
	root->inorder(root);


	cout << "\n After converting to BST. Inorder Traversal \n";

	root = root->convertToBST(root);
	root->inorder(root);
	return 0;
}