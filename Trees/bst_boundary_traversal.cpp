#include <iostream>
#include <map>
#include <vector>

using namespace std;

class tree {


public:

    tree(int n): left( NULL ), right( NULL ), key(n) { }

    tree* insert(tree *node, int _key) {
        if( node == NULL )
            node = new tree(_key);
        else if ( node->key >_key )
            node->left = insert(node->left,_key);
        else
            node->right = insert(node->right,_key);
        
        return node;

    }

    void printLeaves(tree *root) {
        if(root) {
        
        printLeaves(root->left);
        
        if((root->left != NULL) && (root->right != NULL)) {
            cout << root->key << " ";
        }
        
        printLeaves(root->right);
            
        }
    }
    
    void printLeftBorder(tree *root) {
        
        if(root) {
        
        if(root->left != NULL) {
            cout << root->key << " ";
            printLeftBorder(root->left);
            
        }
        else if(root->right != NULL) {
            cout << root->key << " ";
            printLeftBorder(root->right);
            
        }
        }
    }
    
    void printRightBorder(tree *root) {
        
        if(root) {
            if(root->right != NULL) {
                printRightBorder(root->right);
                cout << root->key << " ";
            }
            else if(root->left != NULL){
                printRightBorder(root->left);
                cout << root->key << " ";
            }
        }
    }


    void PrintBorderTraversal(tree *root) {
        if(root) {
            cout << root->key << " ";
            
            printLeftBorder(root->left);
            
            printLeaves(root->left);
            printLeaves(root->right);
            
            printRightBorder(root->right);
        }
    }
    
private:
tree *left;
tree *right;
int key;

};

int main()
{
	tree *root = NULL;
	
	root = root->insert(root,50);
	root = root->insert(root,100);
    root = root->insert(root,80);
	root = root->insert(root,25);
    root = root->insert(root,40);
	root = root->insert(root,20);
	root = root->insert(root,5);
    root->PrintBorderTraversal(root);
    
	return 0;
	

}
