#include <iostream>
#include <queue>
using namespace std;

class tree 
{

public:

	tree(int _val) : left( NULL ), right ( NULL ), value(_val), level(0) {}
	
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

	void inorder_level_new(tree *node, int level)
	{
		if( node != NULL )
		{
			cout<<"value :"<<node->value<<" "<<"level : "<<level<<endl;
			inorder_level_new(node->left,level+1);
			inorder_level_new(node->right,level+1);
		}
	}


	void level_order_traversal( tree *node )
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
	int getval() { return this->value; }

	/*void createTree2(tree** node, int val)
	{

		//cout<<"Enter createTree2 : "<<endl;
		if( (*node) == NULL )
		{
			//cout<<"node is NULL " <<endl;
			*node = new tree();
			(*node)->left = NULL;
			(*node)->right = NULL;
			(*node)->value = val;
		
		}

		else if ( (*node)->value < val )
		{
			createTree2(&((*node)->right),val);

		}

		else
		{

			createTree2(&((*node)->left),val);
		}

	}
*/
	void deleteNode( int val )
	{
		tree *t = this;
		

	
		//todo
	}

private:
	tree *left;
	tree *right;
	int value;
	int level;
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
	
	/*cout<<"Pre-order : " ;
	root->preorder(root);
	cout<<endl;
	
	cout<<"Post-order : ";
	root->postorder(root);
	cout<<endl;*/

	//cout<<"In-order : ";
	/*int a[10];
	root->sum(root,71,0,a,0);
	cout<<endl;*/

	//root->sumpath(root,71,0);

	//root->inorder_level(root,0);


	cout << "\n Level order traveseral \n";
	//root->inorder_level_new(root,0);

	root->level_order_traversal(root);

	/*tree *tr = NULL;
	tr->createTree2(&tr,1000);
	tr->createTree2(&tr,23);
	tr->createTree2(&tr,3456);
	tr->createTree2(&tr,123);
	tr->createTree2(&tr,900);
	tr->createTree2(&tr,9999);

	//cout<<"Value is : "<<tr->getval();
	cout<<endl;
	tr->preorder(tr);*/
	return 0;
}

