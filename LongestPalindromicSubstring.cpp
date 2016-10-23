class Solution {
public:
    string longestPalindrome(string s) {
        
        int i, maxLen = 1, k, start = 0, j;
        
        int len = s.length();
        
        if(len == 0)
            return "";
        else if(len == 1)
            return s;
        else {}
        
        bool table[len][len];
        
        for(i = 0; i < len; i++)
            for(j = 0; j < len; j++)
                table[i][j] = false;
        
        for(i = 0; i < len; i++)
        {
            table[i][i] = true;
        }
        
        for(i = 0; i < len - 1; i++ )
        {
            if(s[i] == s[i+1])
            {
                table[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
            
        }
        
        cout<<"champ"<<endl;
        
        
        //checking palins of size greater than 2
        for(k = 3; k <= len; k++)
        {
            for(i = 0; i < len-k+1; i++)
            {
                j = i+k-1;
                if(s[i] == s[j] && table[i+1][j-1] == true)
                {
                    table[i][j] = true;
                    if(k > maxLen)
                    {
                        start = i;
                        maxLen = k;
                    }
                    
                }
            }
        }
        
        cout<<maxLen<<" "<<start<<endl;
        
        k = 0;
        
        char res[maxLen + 1];
        
        for(i = start; i < start + maxLen; i++)
        {
            res[k] = s[i];
            k++;
        }
        
        res[k] = '\0';
        cout<<res<<endl;
        
        return res;
    }
};
