/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int answer = 0;
    
    int maxDepthBottomUp(TreeNode *root, int depth) {
        
        if(!root) return 0;
        
        int leftDepth = maxDepthBottomUp(root->left, depth + 1);
        int rightDepth = maxDepthBottomUp(root->right, depth + 1);
        
        return max(leftDepth, rightDepth) + 1;
        
    }

    void maxDepthTopDown(TreeNode *root, int depth) {
       if(root == nullptr) {
           answer = max(answer , depth);
           return;
       }
        
        maxDepthTopDown(root->left, depth + 1);
        maxDepthTopDown(root->right, depth + 1);
    }
    
    
    int maxDepth(TreeNode* root) {
      
       // if(!root) return 0;
        
        maxDepthTopDown(root, 0);
        
        return answer;
        
        //return maxDepthBottomUp(root, 1);
       // return answer;
        
        
    }
};