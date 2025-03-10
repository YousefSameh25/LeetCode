class Solution {
public:
    bool valid (int i, int j, int n, int m)
    {
        return i >= 0 and i < n and j >= 0 and j < m;
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {
        vector < vector < int >> grid(m, vector < int > (n, 0));

        for (auto it : guards)
            grid[it[0]][it[1]] = 1;
        
        for (auto it : walls)
            grid[it[0]][it[1]] = 2; 

        for (auto it : guards)
        {
            int i = it[0], j = it[1];
            if (grid[i][j] == 1)
            {
                // right
                int tempi = i, tempj = j + 1;
                while(valid(tempi, tempj, m, n) and grid[tempi][tempj] != 2
                    and grid[tempi][tempj] != 1)
                    grid[tempi][tempj] = 3, tempj++;

                // left
                tempi = i, tempj = j - 1;
                while(valid(tempi, tempj, m, n) and grid[tempi][tempj] != 2
                    and grid[tempi][tempj] != 1)
                    grid[tempi][tempj] = 3, tempj--;

                // up
                tempi = i - 1, tempj = j;
                while(valid(tempi, tempj, m, n) and grid[tempi][tempj] != 2
                    and grid[tempi][tempj] != 1)
                    grid[tempi][tempj] = 3, tempi--;

                // down
                tempi = i + 1, tempj = j;
                while(valid(tempi, tempj, m, n) and grid[tempi][tempj] != 2
                and grid[tempi][tempj] != 1)
                    grid[tempi][tempj] = 3, tempi++;
            }
        }
        int ans = 0;
        for (int i = 0 ; i < m; i++)
        {
            for (int j = 0; j < n ; j++)
            {
                ans += grid[i][j] == 0;
            }
        }
        return ans;
    }
};