#include<iostream>
using namespace std;
class tree 
{

public:

	tree() : left( NULL ), right ( NULL ), value(0) {}
	
	tree* createTree(tree *newNode, int val)
	{
		
		if( newNode == NULL )
		{
			newNode = new tree;
			newNode->left = NULL;
			newNode->right = NULL;
			newNode->value = val;
		}

		else if( val < newNode->value )
		{
			newNode->left  = createTree(newNode->left,val);
		}

		else 
		{
			newNode->right = createTree(newNode->right,val);
		}

		return newNode;
	}
	
	void convertToDLL(tree *root, tree **head)
	{
		if(root == NULL) return;

		static tree *prev = NULL;//keep track of the parent node as well
		convertToDLL(root->left, head);

		if(prev == NULL)
			*head = root;
		else
		{
			root->left = prev;
			prev->right = root;

		}

		prev = root;
		convertToDLL(root->right,head);

	}

	void printDLL(tree *root)
	{
		tree *temp = root;
		while(temp != NULL)
		{
			std::cout << temp->value << " ";
			temp = temp->right;
		}
		std::cout << std::endl;
		
	}


public:
	tree *left;
	tree *right;
	int value;
};

int main()
{
 
	tree *root = NULL;
	root = root->createTree(root,50);
	root = root->createTree(root,100);
	root = root->createTree(root,10);
	root = root->createTree(root,11);
	root = root->createTree(root,8);
	root = root->createTree(root,3);
	root = root->createTree(root,500);
	root = root->createTree(root,1000);
	
	tree *head = NULL;

	root->convertToDLL(root,&head);

	root->printDLL(root);
	
	return 0;
}

