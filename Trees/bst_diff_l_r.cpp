#include<iostream>
using namespace std;
int max1;
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

	void preorder(tree* node)
	{
		if( node != NULL )
		{
			preorder(node->left);
			cout<<node->value<<" ";
			preorder(node->right);

		}
	}

	void postorder(tree* node)
	{
		if( node != NULL )
		{
			postorder(node->left);
			postorder(node->right);
			cout<<node->value<<" ";
		}

	}


	void inorder(tree *node)
	{

		if( node != NULL )
		{
			cout<<node->value<<" ";
			inorder(node->left);
			inorder(node->right);

		}

	}

	int diff(tree **node)
	{
		if( (*node) == NULL ) return 0 ;
		
		int old_val = (*node)->value;
		
		(*node)->value = diff(&((*node)->left))-diff(&((*node)->right));
		
		return (*node)->value-old_val;
	}
		
	int sum(tree **node)
	{
		if( (*node) == NULL ) return 0 ;
		
		int old_val = (*node)->value;
		
		(*node)->value = sum(&((*node)->left))+sum(&((*node)->right));
		
		return (*node)->value+old_val;
	}

private:
	tree *left;
	tree *right;
	int value;
};

int main()
{
 
	tree *root = NULL;
	root = root->createTree(root,5);
	root = root->createTree(root,3);
	root = root->createTree(root,4);
	root = root->createTree(root,2);
	root = root->createTree(root,7);
	root = root->createTree(root,6);
	root = root->createTree(root,8);
	// root = root->createTree(root,1000);
	
	
	root->diff(&root);
	
	cout<<endl;
	
	root->preorder(root);
	

	return 0;
}

