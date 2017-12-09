/****
 Program to convert the tree into tree such that each node value is between min and max
 ****/
#include <iostream>
#include <vector>
using namespace std;
class tree;
vector<int> data;
tree *convertedTree = NULL;

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
    
    
    
    
    tree *convert_tree(tree *root,int min, int max)
    {
        
        if(root) {
            if(root->value >= min && root->value <= max)
            {
                
                convertedTree = createTree(convertedTree,root->value);
            }
            
            convert_tree(root->left,min,max);
            convert_tree(root->right,min,max);
            
        }
        return convertedTree;
        
        //        if(root != NULL)
        //        {
        //            for(int i = 0 ; i < data.size(); i++) {
        //                if(data[i] >= min && data[i] <= max)
        //                    convertedTree = createTree(convertedTree, data[i]);
        //            }
        //        }
        //
        //        return convertedTree;
        
    }
    
    void preorder(tree *root)
    {
        if(root != NULL)
        {
            preorder(root->left);
            std::cout << root->value << " ";
            data.push_back(root->value);
            preorder(root->right);
        }
        //std::cout << std::endl;
        
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
    
    std::cout << "before convertions \n";
    root->preorder(root);
    
    int min = 5;
    int max = 500;
    convertedTree = root->convert_tree(root,min,max);
    
    std::cout << "\n after converting \n";
    convertedTree->preorder(convertedTree);
    return 0;
}


