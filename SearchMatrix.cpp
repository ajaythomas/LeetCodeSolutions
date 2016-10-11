class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int i, m, n, row, col;
        
        row = matrix.size();
        
        if(row == 0)
            return false;
            
        col = matrix[0].size();
        
        m = 0;
        n = col - 1;
        
        while(n >= 0 && m < row)
        {
            if(matrix[m][n] == target)
                return true;
                
            if(matrix[m][n] < target)
            {
                m++;
            }
            else
                n--;
        }
        
        return false;
    }
};
