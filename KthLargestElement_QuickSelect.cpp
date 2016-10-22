class Solution {
public:

    void swap(int *a, int *b)
    {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }

    int partition(vector<int>& nums, int beg, int end)
    {
        //int pivot = end;
        
        int less = beg;
        int more = end - 1;
        
        if(less == more)
        {
            //there are only 2 elements to look at
            if(nums[less] <= nums[end])
                return end;
            else
            {
                swap(&nums[less], &nums[end]);
                return less;
            }
        }
        
        while(less < more)
        {
            if(nums[less] <= nums[end])
            {
                less++;
            }
            else
            {
                swap(&nums[less], &nums[more]);
                more--;
            }
        }
        
        if(nums[more] < nums[end])
        {
            swap(&nums[more + 1], &nums[end]);
            return more + 1;
        }
        else
        {
            swap(&nums[more], &nums[end]);
            return more;
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        
        if(nums.size() == 0)
            return -1;
        
        if(k > nums.size())
            return -1;
        
        //make it kth smallest
        k = nums.size() - k + 1;
        //cout<<"k is "<<k<<endl;
        
        //Quickselect
        
        int index, beg = 0, end = nums.size() - 1;
        
        while(beg < end)
        {
            index = partition(nums, beg, end);
            
            if(index + 1 == k)
            {
                return nums[index];
            }
            else if(k < index + 1)
            {
                //check first half
                end = index - 1;
            }
            else
            {
                //check second half
                beg = index + 1;
                //k = k - index - 1;
            }
        }
        
        return nums[beg];
    }
};
