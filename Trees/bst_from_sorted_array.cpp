#include<iostream>
using namespace std;

class node {
public:
node(int v) : val(v),left(NULL),right(NULL) { }

node* insert(node* n, int _val )
{
	if( n == NULL ) 
		n = new node(_val);
		
	else if( _val > n->val ) 
			n->right = insert(n->right,_val);
		
	else 
		n->left = insert(n->left,_val);
			
		return n;
	
}

	void inorder(node *n)
	{

		if( n != NULL )
		{
			
			inorder(n->left);
			cout<<n->val<<" ";
			inorder(n->right);

		}

	}

private:
node *left,*right;
int val;
};

int bsearch(node **t,int arr[], int start,int end)
{
	int mid;
	if( start > end ) return -1;
	mid = (start+end)/2;
	*t = (*t)->insert(*t,arr[mid]);
	
	bsearch(t,arr,start,mid-1);
	bsearch(t,arr,mid+1,end);
	
	
}

void createTree(int arr[], int start, int end)
{
	node *thenode = NULL;
	bsearch(&thenode,arr,start,end);
	thenode->inorder(thenode);
	
}


int main()
{
	int arry[] = { 1,2,3,4,5,6,7,8,9,10};
	createTree(arry,0,10);
	return 0;
}