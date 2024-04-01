class Solution 
{
public:
    int matrixScore(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid.back().size();
        for (int i = 0 ; i < n;  i++)
        {
             if (grid[i][0] == 0)
             {
                  for (int j = 0 ; j < m ; j++)
                          grid[i][j] = 1 - grid[i][j];
             }
        }
        
        for (int j = 0 ; j < m;  j++)
        {
            int Z = 0;
            for (int i = 0 ; i < n;  i++)
                Z += (grid[i][j] == 0);
            
            if (Z > n - Z)
            {
                for (int i = 0 ; i < n;  i++)
                   grid[i][j] = 1 - grid[i][j];
            }
        }
        int ans = 0;
        for (int i = 0 ; i < n;  i++)
        {
            int num = 0;
            for (int j = 0 ; j < m;  j++)
            {
                if (grid[i][j])
                    num |= (1 << (m - j - 1));
            }
            ans += num;
        }
        return ans;
    }
};