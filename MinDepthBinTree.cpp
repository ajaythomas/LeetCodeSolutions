/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void deepHelp(TreeNode* node, int depth, int* minDepth)
    {
        if(node == NULL)
            return;
        
        if(node->left == NULL && node->right == NULL)
        {
            depth = depth + 1;
            
            if(depth < *minDepth)
                *minDepth = depth;
                
            return;
        }
        
        depth = depth + 1;
        
        deepHelp(node->left, depth, minDepth);
        deepHelp(node->right, depth, minDepth);
        
    }



    int minDepth(TreeNode* root) {
        
        if(root == NULL)
            return 0;
            
        int minDepth = INT_MAX;
        
        deepHelp(root, 0, &minDepth);
        
        return minDepth;
    }
};
