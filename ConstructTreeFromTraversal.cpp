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
    
    TreeNode* TreeHelper(vector<int>& preorder, vector<int>& inorder, int prebeg, int inbeg, int inend)
    {
        if(inbeg > inend)
            return NULL;
            
        TreeNode* root = new TreeNode(preorder[prebeg]);
        
        int i, count = 0;
        
        for(i = inbeg; i <= inend; i++)
        {
            if(inorder[i] == preorder[prebeg])
                break;
                
            count++; //keeps track of how many elements in the left subtree of the root
        }
        
        root->left = TreeHelper(preorder, inorder, prebeg+1, inbeg, i - 1);
        
        inbeg = i + 1;
        
        root->right = TreeHelper(preorder, inorder, prebeg+count+1, inbeg, inend);
        
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(preorder.size() == 0)
            return NULL;
        
        return TreeHelper(preorder, inorder, 0, 0, inorder.size()-1);
        
    }
        
    
};
