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

		
	void sumpath(tree *node, int k,int addition)
	{
		
		if(node != NULL ) {

			cout<<node->value<<" ";
			addition += node->value;
			if( addition == k ) cout<<node->value<<" ";
			else {

				sumpath(node->left,k,addition);
				sumpath(node->right,k,addition);
			}
			
		}
	}
	void sum(tree *node,int k,int addition,int a[],int i)
	{
		if( node != NULL /*&& addition != k*/)
		{
			//cout<<node->value<<" ";
			//cout<<node->value<<" ";
			a[i++]=node->value;			
			addition += node->value;
			if( addition == k ) {
				for(int j=0;j<i;j++)				
				cout<<a[j]<<" ";

				cout<<endl;
			}			
			sum(node->left,k,addition,a,i);
			sum(node->right,k,addition,a,i);

		}
		//cout<<node->value;
	}
	
  bool binarytree(tree * root)
  {
	return(isbst(root,1000,-1000));
  }
  

bool isbst(tree * root,int max, int min)
  {
	 if(root==NULL)
		return true;
		
		
		
		if(root->value>max || root->value<min)
			return false;
			
		return((isbst(root->left,root->value,min)) && (isbst(root->right,max, root->value)));
		
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

	void deleteNode( int val )
	{
		tree *t = this;
		

	
		//todo
	}
	
	void printAllPaths(tree *root)
	{
		if( root != NULL )
		{
			// if( root->left != NULL )
			// {
				cout<<root->value<<" ";
				printAllPaths(root->left);
				printAllPaths(root->right);
			// }
			cout<<endl;
			// if( root->right != NULL )
			// {
				
				// 
				// cout<<root->value<<" ";
			// }
			
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

	//cout<<"Max is "<<root->findmax(root,0)<<endl;
	
	//root->printAllPaths(root);

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
	
	cout<<root->binarytree(root)<<endl;
	
	return 0;
}

