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

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
    
    int getHeight(TreeNode* root)
    {
        if(root == NULL)
            return -1;
            
        int leftHeight = getHeight(root->left);
        
        if(leftHeight == -2)
            return -2;
        
        int rightHeight = getHeight(root->right);
        
        if(rightHeight == -2)
            return -2;
            
        int diff = leftHeight - rightHeight;
        
        if(diff > 1 || diff < -1)
            return -2;

        return max(leftHeight,rightHeight) + 1;            
    }

    bool isBalanced(TreeNode* root) {
        
        return getHeight(root) != -2;
        
    }
};
