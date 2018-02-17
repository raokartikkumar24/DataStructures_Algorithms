#include <iostream>
using namespace std;

class tree 
{

public:

	tree(int _val) : left( NULL ), right ( NULL ), value(_val) {}
	
	tree* createTree(tree *newNode, int val)
	{
		
		if( newNode == NULL )
			newNode = new tree(val);

		else if( val < newNode->value )
			newNode->left  = createTree(newNode->left,val);

		else 
			newNode->right = createTree(newNode->right,val);

		return newNode;
	}

	void preorder(tree* node)
	{
		if( node != NULL )
		{
			cout<<node->value<<" ";
			preorder(node->left);
			//cout<<node->value<<" ";
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

    
    void leftView(tree *root, int level, int *max_level) {
        
        if(!root) return;
        
        if(*max_level < level) {
            cout << root->value << "\t";
            *max_level = level;
        }
        
        leftView(root->left, level+1, max_level);
        leftView(root->right, level+1, max_level);
        
    }

    void leftViewUtil(tree *root) {
        int max_val = 0;
        leftView(root,1,&max_val);
    }
	

private:
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
	root = root->createTree(root,80);
	root = root->createTree(root,500);
	
	root->leftViewUtil(root);

	return 0;
}

