class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> & grid)     {
        int n  = grid.size();
        vector < int > r (n , 0) , c (n , 0);
        for (int i = 0 ; i < n; i++ )
        {
            for (int j = 0 ; j < n ; j++)
            {
                r[i] = max(r[i] , grid[i][j]);
                c[i] = max(c[i] , grid[j][i]);
            }
        }
    
         int sum = 0;
         for (int i = 0 ; i < n; i++ )
        {
            for (int j = 0 ; j < n ; j++)
            {
                sum +=  min(r[i] , c[j]) - grid[i][j];
            }
        }
        return sum;
    }
};