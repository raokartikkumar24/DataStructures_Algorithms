#include<iostream>
#include<stack>
using namespace std;
int max1;
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

	

		

	int getval() { return this->value; }

	void createTree2(tree** node, int val)
	{

		//cout<<"Enter createTree2 : "<<endl;
		if( (*node) == NULL )
		{
			//cout<<"node is NULL " <<endl;
			*node = new tree(val);
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

void zigzag(tree *tr)
{
	stack<tree*> st1,st2;
	st1.push(tr);
	bool left = false;
	while( ! st1.empty() )
	{
		tree *temp = st1.top();
		st1.pop();
		if( temp != NULL )
		{
			cout<<temp->value<<" ";
			if( left )
			{
				st2.push(temp->right);
				st2.push(temp->left);
			}
			else
			{
				st2.push(temp->left);
				st2.push(temp->right);
			}
		}

	if( st1.empty() )
	{
		cout<<endl;
		swap(st1,st2);
		left = !left;
	}	

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
	root = root->createTree(root,70);
	root = root->createTree(root,60);
	root = root->createTree(root,80);
	root = root->createTree(root,55);
	root = root->createTree(root,65);
	root = root->createTree(root,100);
	root = root->createTree(root,75);

	root->zigzag(root);
	
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

