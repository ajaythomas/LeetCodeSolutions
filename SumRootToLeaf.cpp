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


    int dfs(TreeNode* node, int num, int sum){
        if(node == NULL) return sum;
     
        num = num*10 + node->val;
     
        // leaf
        if(node->left == NULL && node->right == NULL) {
            sum = sum + num;
            return sum;
        }
     
        // left subtree + right subtree
        return dfs(node->left, num, sum) + dfs(node->right, num, sum);
    }

    int sumNumbers(TreeNode* root) {
        
        if(root == NULL)
            return 0;
            
        //vector<int> digits;
        //return sumHelper(root, digits);
        
        return dfs(root, 0, 0);
    }
    
   
    
};
