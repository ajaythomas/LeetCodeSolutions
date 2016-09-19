/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        
        if(root == NULL)
            return;
            
        auto leftNode = root;
        
        while(leftNode)
        {
            TreeLinkNode* parent = leftNode;
            
            while(parent && parent->left)
            {
                parent->left->next = parent->right;
                
                if(parent->next)
                    parent->right->next = parent->next->left;
                    
                parent = parent->next;
            }
            
            leftNode = leftNode->left;
            
        }
        
    }
};
