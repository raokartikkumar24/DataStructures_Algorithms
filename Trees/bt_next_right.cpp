#include <iostream>
#include <queue>
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


	tree* updateNextRight(tree *root, int k) {
            if(!root) return NULL;
        
			queue<tree*> q;
            queue<int> q1;
			q.push(root);
            int level = 0;
            q1.push(level);
			while(!q.empty()) {

				tree* val = q.front();
                level = q1.front();
				q.pop();
                q1.pop();
                if(val->value == k) {
                    if (q1.size() == 0 || q1.front() != level)
                        return NULL;
                    
                    return q.front();
                }
                
                if (val->left != NULL)
                {
                    q.push(val->left);
                    q1.push(level+1);
                }
                if (val->right != NULL)
                {
                    q.push(val->right);
                    q1.push(level+1);
                }
            }
         return NULL;
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
	
	root->updateNextRight(root,100);

	return 0;
}

