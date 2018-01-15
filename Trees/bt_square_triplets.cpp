/**
Given a binary tree, count the triplets in the tree. Triplets are defined as nodes forming a combination as value, (parent->value)2 , (parent->value)3
**/
#include <iostream>
using namespace std;

int triplets = 0;
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
			preorder(node->right);

		}
	}


	void countTriplets(tree *root, tree *parent)
	{
		if(root)
		{
			tree *par = parent;
			countTriplets(root->left,root);
            if(par) {
                int inter = par->value/root->value;
                if(root->left)
                {
                    if(inter == root->left->value && ((inter*inter) == root->value))
                    {
                        triplets++;
                    } 
                }
                if(root->right)
                {
                    if(inter == root->right->value && ((inter*inter) == root->value))
                    {
                        triplets++;
                    }
                }
            }
			countTriplets(root->right,root);
		}

	}
	
	public:
	tree *left;
	tree *right;
	int value;
};

int main()
{
 
	tree *root = new tree(41);
	root->left = new tree(27);
    root->right = new tree(8);
    root->right->right = new tree(4);
    root->right->right->right = new tree(2);
	root->left->left = new tree(9);
    root->left->right = new tree(99);
	root->left->left->left = new tree(3);

	root->countTriplets(root,NULL);
	printf("Triplets : %d\n",triplets);
	return 0;
}

