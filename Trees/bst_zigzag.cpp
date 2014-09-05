
#include<iostream>
#include<stack>
using namespace std;

class node {
public:
node(int v) : val(v),left(NULL),right(NULL) { }

node* insert(node* n, int _val )
{
	if( n == NULL ) {
		n = new node(_val);
		}
	else if( _val > n->val ) {
		//n->childvals+=_val;
		n->right = insert(n->right,_val);
		}
	else {
		//n->childvals+=_val;
		n->left = insert(n->left,_val);
		}
		
		return n;
	
}

void zigzag(node *t)
{
	stack<node*> st, st2;
	st.push(t);
	
	while( !st.empty() )
	{
		node *temp = st.top();
		st.pop();
		if( temp != NULL)
		{
			cout<<temp->val<<" ";
			st2.push(temp->left);
			st2.push(temp->right);
		}
		if( st.empty() )
		{
			cout<<endl;
			swap(st,st2);
		}
	}
}


void inorder(node *t)
{
	if( t  )
	{
		cout<<t->val<<" ";
		inorder(t->left);
		inorder(t->right);
	}

}

// node* modifyTree(node *t)
// {
	// if( t ) {
		// t->val = t->childvals;
		// t->left = modifyTree(t->left);
		// t->right = modifyTree(t->right);
	// }
	// return t;
// }

public:
int val;

node *left,*right;
};

int main()
{
	node *newNode = NULL;
	newNode = newNode->insert(newNode,30);
	//node *otherNode = newNode;
	newNode = newNode->insert(newNode,10);
	
	newNode = newNode->insert(newNode,50);
	
	newNode = newNode->insert(newNode,5);
	
	newNode = newNode->insert(newNode,15);
	
	newNode = newNode->insert(newNode,40);
	
	newNode = newNode->insert(newNode,70);
	
	cout<<endl;
	//newNode->inorder(newNode);
	cout<<endl;
	//otherNode = otherNode->modifyTree(otherNode);
	//newNode = newNode->modifyTree(newNode);
	cout<<endl;
	//otherNode->inorder(otherNode);
	//newNode->inorder(newNode);
	newNode->zigzag(newNode);
	cout<<endl;
	return 0;
}
