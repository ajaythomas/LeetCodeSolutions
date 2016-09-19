class Solution {
public:

    int max(int a, int b, int c)
    {
        int maximum;
        
        if(a > b)
            maximum = a;
        else
            maximum = b;
            
        if(maximum > c)
            return maximum;
        else
            return c;
    }
    
    int max(int a, int b)
    {
        int maximum;
        
        if(a > b)
            maximum = a;
        else
            maximum = b;
            
        return maximum;
        
    }
    
    int min(int a, int b, int c)
    {
        int minimum;
        
        if(a < b)
            minimum = a;
        else
            minimum = b;
            
        if(minimum < c)
            return minimum;
        else
            return c;
        
    }

    int maxProduct(vector<int>& nums) {
        
        int curr_max_prod, curr_min_prod, prev_max_prod, prev_min_prod, ans;
        
        curr_max_prod = nums[0];
        prev_max_prod = nums[0];
        curr_min_prod = prev_min_prod = nums[0];
        ans = nums[0];
    
        for(int i=1; i < nums.size(); i++)
        {
             curr_max_prod = max ( prev_max_prod*nums[i],  
                                                         prev_min_prod*nums[i], 
                                                         nums[i] );
        
             curr_min_prod = min ( prev_max_prod*nums[i],  
                                                         prev_min_prod*nums[i], 
                                                         nums[i] );
             ans = max(ans, curr_max_prod);
             prev_max_prod = curr_max_prod;
             prev_min_prod = curr_min_prod;
        }
        return ans;    
        
        
        
    }
};
