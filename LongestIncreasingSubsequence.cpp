class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        
        int i, j;
        
        if(nums.size() == 0)
            return 0;
        
        vector<int> sublen;
        
        //O(n) space
        for(i = 0; i < nums.size(); i++)
        {
            sublen.push_back(1);
        }
        
        //O(n^2) time
        for(i = 1; i < nums.size(); i++)
        {
            for(j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                {
                    if(sublen[i] < (sublen[j] + 1))
                        sublen[i] = sublen[j] + 1;
                }
            }
        }
        
        int max = 1;
        
        for(i = 1; i < sublen.size(); i++)
        {
            if(sublen[i] > max)
            {
                max = sublen[i];
            }
        }
        
        return max;
    }
};
