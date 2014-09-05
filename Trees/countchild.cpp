#include<iostream>

using namespace std;

class node {
private:
int value;
int leftChilds;
int rightChilds;
node *left;
node *right;
public:
node( int val ) : value( val ), leftChilds( 0 ), rightChilds( 0 ), left( NULL ), right ( NULL ) { }


node *insertNode(node *theNode, int val)
{

 	if( theNode == NULL )
	{
		theNode = new node(val);
	}

	else if ( val < theNode->value )
	 {
		theNode->leftChilds++;
		theNode->left = insertNode(theNode->left,val);
	 }

	else
	{
		theNode->rightChilds++;
		theNode->right = insertNode(theNode->right,val);
	}

	return theNode;

}

node *inorder(node *n )
{

	if( n )
	{
		cout<<"value is : "<<n->value<<" Left Childs : "<<n->leftChilds<<" right childs : "<<n->rightChilds<<endl;
		inorder(n->left);
		inorder(n->right);
		
	}
}

};


int main()
{
  node *mynode = NULL;
  mynode = mynode->insertNode(mynode,50);
  mynode = mynode->insertNode(mynode,100);
  mynode = mynode->insertNode(mynode,25);
  mynode = mynode->insertNode(mynode,20);
  mynode = mynode->insertNode(mynode,500);
  mynode = mynode->insertNode(mynode,75);
  mynode = mynode->insertNode(mynode,150);
  mynode = mynode->insertNode(mynode,225);

	cout<<endl;
	mynode->inorder(mynode);

	delete mynode;
	return 0;

	
}
