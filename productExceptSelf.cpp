class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int i = 0;
        
        //create a product array and initialize all elements to 1
        vector<int> product(nums.size(), 1);
        
        product[0] = 1;
        
        //initially elements of product will be equal to the left product of corresponding element in nums
        for(i = 1; i < nums.size(); i++)
        {
            product[i] = product[i-1] * nums[i-1];
        }
        
        int temp = 1;
        
        //get their right products by using a temp variable
        for(i = nums.size()-1; i >= 0; i--)
        {
            product[i] = temp * product[i];
            temp = temp * nums[i];
        }
        
        return product;
        
    }
};
