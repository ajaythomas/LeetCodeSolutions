class Solution {
public:
    bool canPermutePalindrome(string s) {
        
        unordered_map<char,int> table;
        
        for(int i = 0; i < s.length(); i++)
        {
            table[s[i]]++;
        }
        
        int count = 0; //keeps track of chars without pairs
        
        for(auto it = table.begin(); it != table.end(); it++ )
        {
            if(it->second % 2 != 0)
                count++;
            
        }
        
        if(s.length() % 2 == 0)
        {
            if(count == 0)
                return true;
            else
                return false;
        }
        else
        {
            if(count == 0)
            {
                cout<<"Impossible"<<endl;
                return false;
            }
            else if (count == 1)
            {
                return true;
            }
            else
                return false;
                
            
        }
        
    }
};
