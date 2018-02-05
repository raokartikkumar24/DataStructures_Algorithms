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

    void printDiagonalLines(tree *root, int hd, map<int, vector<int> > &vLines) {
        
        if(root == NULL) return;
        
        vLines[hd].push_back(root->key);
        
        printDiagonalLines(root->left, hd+1, vLines);
        printDiagonalLines(root->right, hd, vLines);
        
    }
    
    void printDiagonalLinesUtil(tree *root) {
        
        map<int, vector<int> > diagLines;
        printDiagonalLines(root,0,diagLines);
        map< int,vector<int> > :: iterator it;
        for (it=diagLines.begin(); it!=diagLines.end(); it++)
        {
            cout << it->first << " --> ";
            for (int i=0; i<it->second.size(); ++i)
                cout << it->second[i] << " ";
            cout << "\n";
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
    root->printDiagonalLinesUtil(root);
    
	return 0;
	

}
