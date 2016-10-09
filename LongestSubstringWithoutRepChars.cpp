class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int i = 0, len = s.length();
        
        if(len == 0)
            return 0;
            
        unordered_map<char, int> a;
        
        a[s[i]] = 0;
        
        //cout<<"a begin is "<<*a.begin()<<endl;
        
        i++;
        int count = 1, maxLen = 0;
        
        while(i < len)
        {
            auto it = a.find(s[i]);
            
            if(it == a.end() || i - count > a[s[i]])
            {
                a[s[i]] = i;
                count++;
                //cout<<"Inserting "<<s[i]<<endl;
                //cout<<*a.begin()<<endl;
                
            }
            else
            {
                //stop continuing, we found a duplicate element
                
                if(count > maxLen)
                    maxLen = count;
                    
                //cout<<"Maxlen is "<<maxLen<<endl;
                //cout<<"it is "<<*it<<endl;
                
                int beg = i + 1 - count;
                int diff = a[s[i]] - beg + 1;
                
                count = count - diff - 1;
                
                //cout<<"Count is "<<count<<endl;
                
                a[s[i]] = i;
                count++;
            }
            
            i++;
        }
        
        if(count > maxLen)
            maxLen = count;
        
        return maxLen;
        
    }
};
