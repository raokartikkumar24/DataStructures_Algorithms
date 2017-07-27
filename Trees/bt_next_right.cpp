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

	void inorder_level(tree *node,int level)
	{

		if( node != NULL )
		{
			node->level = level;
			cout<<"value :"<<node->value<<" "<<"level : "<<level<<endl;
			level++;
			inorder_level(node->left,level);
			inorder_level(node->right,level);

		}

	}

	{
			queue<tree*> q;
			q.push(node);

			while(!q.empty())
			{
				

				tree* val = q.front();
				cout << val->value << " ";
				
				

				if(  val->left != NULL )
					q.push(val->left);
				if( val->right != NULL )
					q.push(val->right);

				q.pop();



			}

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
	

	return 0;
}

