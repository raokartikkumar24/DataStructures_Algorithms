#include <iostream>
#include <queue>
using namespace std;

class tree 
{

public:

	tree(int _val) : left( NULL ), right ( NULL ), nextRight(NULL), value(_val) {}
	
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
            if(node->nextRight) {
			cout<<node->nextRight->value<<" ";
			preorder(node->left);
			preorder(node->right);
            }
		}
	}


	void updateNextRight(tree *root) {
        if(!root) return;
        queue<tree*> nodes;
        nodes.push(root);
        nodes.push(NULL); //marking end of the level
        
        while(!nodes.empty()) { //here we check if we have already visited that level
            tree *temp = nodes.front();
            nodes.pop();
            if(temp) {
                temp->nextRight = nodes.front();
                
                if(temp->left) nodes.push(temp->left);
                if(temp->right) nodes.push(temp->right);
            }
            else if(!nodes.empty()) //mark that this level is done visiting
                nodes.push(NULL);
        }
			
    }
	

private:
	tree *left;
	tree *right;
    tree *nextRight;
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
	
	root->updateNextRight(root);
    root->preorder(root);

	return 0;
}

