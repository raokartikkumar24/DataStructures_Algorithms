//  binary tree is bst or not?
  
  
#include<iostream>
//#include<ctype.h>

using namespace std;
  class Node 
  {
  public:
  
  int key;
  Node *left,*right;
  
  Node(int n) : key(n),left(NULL),right(NULL ) { } 
  
  
 
  
  

  
  
  bool binarytree(Node * root)
  {
	return(isbst(root,1000,-1000));
  }
  
  
  bool isbst(Node * root,int max, int min)
  {
	 if(root==NULL)
		return true;
		
		
		
		if(root->key>max || root->key<min)
			return false;
			
		return((isbst(root->left,root->key-1,min) && isbst(root->right,max, root->key+1));
		
  }
  
  };
  
  int main()
  {
	Node *root = new Node(5);
	root->left->key = 3;
	root->right->key = 17;
	
	root->left->left->key = 1;
	root->left->right->key = 8;
	
	cout<<binarytree(root)<<endl;
	
	return 0;
	
  
  
  }
