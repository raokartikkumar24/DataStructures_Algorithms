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
			cout<<node->value<<" ";			
			preorder(node->left);
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
			inorder(node->left);
			cout<<node->value<<" ";
			inorder(node->right);

		}

	}

	bool search(tree *node, int val)
	{

		bool found = false;

		if( node != NULL )
		{
			if( node->value ==  val ) return true;
			found = search(node->left,val);
			found = search(node->right,val);
		}
	}

	tree* lca(tree* node, int val1, int val2)
	{
		tree *root = node;
		if( search( root,val1) && search(root, val2 ) )
			return root;
		else {
			root = lca(root->left,val1,val2);
			root = lca(root->right,val1,val2);
		}
		
	}

	int findmax(tree *node,int max)
	{

		if( node != NULL )
		{
			//cout<<node->value<<" ";
			if( node->value > max ) 
				max = node->value;
			max = findmax(node->left,max);
			max = findmax(node->right,max);

		}

		return max;
	}

		
	

	int getval() { return this->value; }

	void createTree2(tree** node, int val)
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

	
public:
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
	root = root->createTree(root,3);
	root = root->createTree(root,500);
	root = root->createTree(root,1000);
	
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
	tree* x = root->lca(root,10,11);
	x->getval();
	//cout<<"Max is "<<root->findmax(root,0)<<endl;


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

