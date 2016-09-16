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

    bool isSymHelper(TreeNode* tree1, TreeNode* tree2)
    {
        if(!tree1 && !tree2)
            return true;
            
        if(!tree1 && tree2)
            return false;
            
        if(tree1 && !tree2)
            return false;
            
        if(tree1->val != tree2->val)
            return false;
            
        return isSymHelper(tree1->left, tree2->right) && isSymHelper(tree1->right, tree2->left);
    }


    bool isSymmetric(TreeNode* root) {
        
        if(root == NULL)
            return true;
            
        return isSymHelper(root->left, root->right);
        
    }
};
