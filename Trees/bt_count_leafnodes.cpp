
#include <iostream>
using namespace std;

int triplets = 0;
class tree 
{

public:

	tree(int _val) : left( NULL ), right ( NULL ), value(_val) {}
	
    //will fail if there is another call to the same function in the same process space
    int countLeafNodes(tree *root)
    {
        static int leafNodes = 0;
  
        if(root) {
            countLeafNodes(root->left);
            if(root->left == NULL && root->right == NULL){
                leafNodes++;
            }
            countLeafNodes(root->right);
        }
        
        return leafNodes;
    }
    
    int countLeafNodes2(tree *root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        return countLeafNodes2(root->left) + countLeafNodes2(root->right);
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

	int NofoLeafNodes = root->countLeafNodes2(root);
	printf("leaf nodes are : %d\n",NofoLeafNodes);
	return 0;
}

