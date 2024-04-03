class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int n = matrix.size(), m = matrix.back().size();
        
        for (int i = 0 ; i < n; i++)
        {
            for (int j = 1 ; j < m ; j++)
            {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        
        for (int j = 0; j < m ; j++)
        {
            for (int i = 1; i < n; i++)
            {
                matrix[i][j] += matrix[i - 1][j];
            }
        }
        
        int L = min(n , m);
        
        int ans = 0;
        
        for (int i = 0; i < n ; i++)
        {
            for (int j = 0 ; j < m ; j++)
            {
                // Try all square side lengths
                for (int l = 1; l <= L; l++)
                {
                    if (i + l - 1 < n and j + l - 1 < m)
                    {
                        int BR = matrix[i + l - 1][j + l - 1];
                        
                        int TL = 0;
                        if (i - 1 >= 0 and j - 1 >= 0)
                            TL = matrix[i - 1][j - 1];
                        
                        int TR = 0;
                        if (i - 1 >= 0)
                            TR = matrix[i - 1][j + l - 1];
                        
                        int BL = 0;
                        if (j - 1 >= 0)
                            BL = matrix[i + l - 1][j - 1];
                        
                        int squareSum = BR - TR - BL + TL;
                        
                        ans += squareSum == l * l;
                    }
                }
            }
        } 
        return ans;   
    }
};