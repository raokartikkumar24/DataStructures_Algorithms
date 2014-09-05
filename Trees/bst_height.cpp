#include<iostream>
using namespace std;

class tree {


public:

tree(int n): left( NULL ), right( NULL ), key(n) { }

tree* insert(tree *node, int _key)
{
	if( node == NULL )
		node = new tree(_key);
	else if ( node->key >_key )
		node->left = insert(node->left,_key);
	else
		node->right = insert(node->right,_key);
		
	return node;

}

int height(tree *node)
{
	int left ;
	int right;
	
	if( node == NULL ) { return -1; }
	
	left = height(node->left);
	right = height(node->right);
	
	
	return 1 + ((left>right)?left:right);
	
}

void heightOfTree(tree *node)
{

	if( node != NULL )
		cout<<height(node->left) - height(node->right)<<endl;
		
}

void inorder(tree *node )
{
	if(node != NULL )
	{
		inorder(node->left);
		cout<<node->key<<" ";
		inorder(node->right);
	}
}

private:
tree *left;
tree *right;
int key;

};

int main()
{
	tree *root = NULL;
	
	root = root->insert(root,50);
	root = root->insert(root,100);
	root = root->insert(root,25);
	root = root->insert(root,20);
	root = root->insert(root,5);
	
	root->inorder(root);
	
	cout<<endl;
	
	cout<<"Height of the BST is : "<<endl;
	root->heightOfTree(root);
	
	return 0;
	

}