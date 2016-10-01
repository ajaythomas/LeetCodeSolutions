class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> table;
        
        vector<int> result(2);
        
        for(int i = 0; i < nums.size(); i++)
        {
            auto index = table.find(target - nums[i]);
            
            if(index == table.end())
            {
                table[nums[i]] = i;
            }
            else
            {
                result[0] = table[target - nums[i]];
                result[1] = i;
                return result;
            }
            
        }
        
        result[0] = result[1] = -1;
        return result;
        
    }
};
