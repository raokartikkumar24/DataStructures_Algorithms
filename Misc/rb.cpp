#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
typedef long long LL;
using namespace std;

bool RED = true;
bool BLACK = false;

ofstream sortedStream("imsorted.txt");

class tree 
{

public:

	tree(int val) : left( NULL ), right ( NULL ), value(val),color(RED) {}
	

	bool isRed(tree *node) 
	{

		
		if(node == NULL ) return false;
		return( node->color == RED );
	}


	void flipcolors(tree **node )
	{
		
		(*node)->color = !((*node)->color);
		(*node)->left->color = !((*node)->left->color);
		(*node)->right->color = !((*node)->right->color);
	}

	tree* createTree(tree *newNode, int val)
	{
		
		if( newNode == NULL )
		{
			newNode = new tree(val);
			return newNode;
		}


		if( isRed(newNode->left) && isRed(newNode->right) ) flipcolors(&newNode);
		
		if(val == newNode->value) newNode->value = val;

		else if( val < newNode->value )
			newNode->left  = createTree(newNode->left,val);
		
		else 	newNode->right = createTree(newNode->right,val);
	
		if( isRed(newNode->left) && isRed(newNode->left->left) )
			 newNode = rotateRight(newNode);

		
		if( isRed(newNode->right) ) 
			newNode = rotateLeft(newNode);
				

		return newNode;
	}


	tree *rotateLeft(tree *node)
	{
		tree* temp = node->right;
		node->right = temp->left;
		temp->left = node;
		temp->color = node->color;
		node->color = RED;
		return temp;
	
	}


	tree *rotateRight(tree* node)
	{

		tree *temp = node->left;
		node->left = temp->right;
		temp->right = node;
		temp->color = node->color;
		node->color = RED;
		return temp;
	}
	

	tree *splitFourNode(tree *node)
	{
		tree *temp = rotateRight(node);
		temp->left->color = BLACK;
		return temp;
	
	}

	tree *leanLeft(tree *node )
	{
		
		tree *temp = rotateLeft(node);
		temp->color = temp->left->color;
		temp->left->color = RED;
		return temp;

	}

	void preorder(tree* node)
	{
		if( node != NULL )
		{
			sortedStream<<node->value<<"\n";
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
			sortedStream<<node->value<<"\n";
			inorder(node->right);

		}

	}

	

	int getval() { return this->value; }

private:
	tree *left;
	tree *right;
	LL value;
	bool color;//false : black, true : red

};


int main()
{
 
	
	tree *root = NULL;

	ifstream numstream("sortedList.txt");
	string csNumbers;

	cout<<"Inserting the elements into the tree. Please wait..."<<endl;
	while( !numstream.eof() )
	{
		getline(numstream,csNumbers);
		LL theval = atoi(csNumbers.c_str());
		if( theval == 0 ) break;
		root = root->createTree(root,theval);
		

	}

	numstream.close();
	

	cout<<"Done adding"<<endl;
	cout<<"Sorted List can be found at sortedList.txt"<<endl;
	root->inorder(root);
	cout<<"The root of this tree is : "<<root->getval()<<endl;
	cout<<endl;
	
	return 0;
}

