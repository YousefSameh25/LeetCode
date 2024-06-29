class Solution {
public:
    bool vis[300][300];
    int X[4] = {0, 0, 1, -1};
    int Y[4] = {1, -1, 0, 0};
    
    bool valid (int i, int j, int n, int m)
    {
        return i >= 0 and i < n and j >= 0 and j < m; 
    }
    
    void dfs(int i, int j, vector<vector<char>>& grid)
    {
        vis[i][j] = 1;
        for (int x = 0 ; x < 4 ; x++)
        {
            int ci = i + X[x];
            int cj = j + Y[x];
            if (valid(ci, cj, grid.size(), grid[0].size()) and grid[ci][cj] == '1' and !vis[ci][cj])
                dfs(ci, cj, grid);
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0 ; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (vis[i][j] or grid[i][j] == '0')
                    continue;
                ans++;
                dfs(i, j, grid);
            }
        }
        return ans;
    }
};