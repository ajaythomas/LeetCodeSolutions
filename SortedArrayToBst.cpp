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

    TreeNode* Helper(vector<int>& nums, int beg, int end)
    {
        if(beg < end)
        {
            int mid = beg + (end - beg)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = Helper(nums,beg,mid-1);
            root->right = Helper(nums, mid + 1, end);
            return root;
        }
        else if(beg == end)
        {
            return new TreeNode(nums[beg]);
        }
        else
        {
            return NULL;
        }
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if(nums.size() == 0)
        {
            return NULL;
        }
        else if(nums.size()== 1)
        {
            return new TreeNode(nums[0]);
        }
        else
        {
            return Helper(nums, 0, nums.size() - 1);
        }
        
        
    }
};
