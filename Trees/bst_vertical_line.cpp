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

    void printVerticalLines(tree *root, int hd, map<int, vector<int> > &vLines) {
        
        if(root == NULL) return;
        
        vLines[hd].push_back(root->key);
        
        printVerticalLines(root->left, hd-1, vLines);
        
        printVerticalLines(root->right, hd+1, vLines);
        
    }
    
    void printVerticalLinesUtil(tree *root) {
        
        map<int, vector<int> > verticalLines;
        printVerticalLines(root,0,verticalLines);
        map< int,vector<int> > :: iterator it;
        for (it=verticalLines.begin(); it!=verticalLines.end(); it++)
        {
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
    root->printVerticalLinesUtil(root);
    
	return 0;
	

}
