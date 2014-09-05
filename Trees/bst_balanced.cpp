#include<iostream>
using namespace std;
int max1;
class tree 
{
private:
tree *left;
	tree *right;
	int value;
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
	
	bool isBalanced(tree *node)
	{
		
		tree *l = node->left;
		tree *r = node->right;
		int lcount = 0 , rcount = 0;
		
		while( l )
		{
			l= l->left;
			lcount++;
		}
		
		while( r )
		{
			r = r->right;
			rcount++;
		}
		
		cout<<"Left : "<<lcount<<" "<<"Right : "<<rcount<<endl;
		
		int diff = lcount > rcount ? lcount - rcount : rcount-lcount;
		
		if( diff > 1 ) return false;
		
		return true;
		
	}
};

int main()
{
 
	tree *root = NULL;
	root = root->createTree(root,50);
	root = root->createTree(root,100);
	root = root->createTree(root,10);
	//root = root->createTree(root,5);
	//root = root->createTree(root,3);
	
	bool re = root->isBalanced(root);
	if( re ) cout<<endl<<"balanced"<<endl;
	else cout<<endl<<"unbalanced"<<endl;
	return 0;
	
}