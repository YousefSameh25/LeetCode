class Solution {
public:
    map < vector < int >, int> mp;
    bool valid(int i, int j, int n, int m)
    {
        return i < n and i >= 0 and j < m and j >= 0;
    }

    int dfs(int i, int j, int prv ,vector<vector<int>>& grid)
    {
        if (!valid(i , j, grid.size(), grid.back().size()) or grid[i][j] <= prv)
            return -1;

        if (mp.count({i,j,prv}))
            return mp[{i,j,prv}];
        
        return mp[{i,j,prv}] = max({
            dfs(i - 1, j + 1, grid[i][j], grid) + 1,
            dfs(i, j + 1, grid[i][j], grid) + 1,
            dfs(i + 1, j + 1, grid[i][j], grid) + 1
        });
    }

    int maxMoves(vector<vector<int>>& grid) 
    {
        int mx = -1;
        for (int i = 0 ; i < grid.size() ; i++)
            mx = max(mx, dfs(i, 0, -1, grid));   
        return mx; 
    }
};