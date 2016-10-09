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

    void deepHelp(TreeNode* node, int depth, int* maxDepth)
    {
        if(node == NULL)
        {
            if(depth > *maxDepth)
                *maxDepth = depth;
                
            return;
        }
        
        depth = depth + 1;
        
        deepHelp(node->left, depth, maxDepth);
        deepHelp(node->right, depth, maxDepth);
        
    }

    int maxDepth(TreeNode* root) {
        
        if(root == NULL)
            return 0;
            
        int maxDepth = 0;
        
        deepHelp(root, 0, &maxDepth);
        
        return maxDepth;
        
    }
};
