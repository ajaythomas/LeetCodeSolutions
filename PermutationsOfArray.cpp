class Solution {
public:

    vector<vector<int>> list;

    void swap(int* a, int* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }


    void permuteList(vector<int>& nums, int beg, int end)
    {   
        int i;
        if (beg == end)
            list.push_back(nums);
        else
        {
           for (i = beg; i <= end; i++)
           {
              swap(&nums[beg], &nums[i]);
              permuteList(nums, beg+1, end);
              swap(&nums[beg], &nums[i]); //backtrack
           }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        permuteList(nums, 0, nums.size() - 1);
        
        return list;
    }
};
