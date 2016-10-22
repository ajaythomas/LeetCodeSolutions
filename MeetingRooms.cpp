/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        if(intervals.size() == 0)
            return true;
        
        int i, j, len, temp, smallest;
        
        len = intervals.size();
        
        
        //bubble sort O(n^2)
        //can do better like counting sort or merge sort
        for(i = 0; i < len - 1; i++)
        {
            smallest = i;
            for(j = i + 1; j < len; j++)
            {
                if(intervals[j].start < intervals[smallest].start)
                    smallest = j;
            }
            
            if(smallest != i)
            {
                //swap i and smallest
                temp = intervals[smallest].start;
                intervals[smallest].start = intervals[i].start;
                intervals[i].start = temp;
                
                temp = intervals[smallest].end;
                intervals[smallest].end = intervals[i].end;
                intervals[i].end = temp;
            }
        
        }
        
        for(i = 1; i < len; i++)
        {
            
            if(intervals[i].start < intervals[i - 1].end)
                break;
        }
        
        if(i == len)
            return true;
        else
            return false;
        
    }
};
