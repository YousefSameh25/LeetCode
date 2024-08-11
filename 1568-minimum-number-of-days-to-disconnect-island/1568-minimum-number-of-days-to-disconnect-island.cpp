class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool valid (int i , int j, int n, int m)
    {
        return i >= 0 and i < n and j >= 0 and j < m;
    }
    void dfs (int i, int j, vector<vector<int>>& grid, vector < vector < bool > > &vis)
    {
        vis[i][j] = 1;
        for (int k = 0 ; k < 4 ; k++)
        {
            int iChild = i + dx[k], jChild = j + dy[k];
            if (!valid(iChild, jChild, grid.size(), grid.back().size()))
                continue;
            if (vis[iChild][jChild] or !grid[iChild][jChild])
                continue;
            dfs(iChild, jChild, grid, vis);
        }
    }
    int NumberofIslands (vector<vector<int>>& grid)
    {
        int numOfIslands = 0;
        int n = grid.size(), m = grid.back().size();
        vector < vector < bool > > vis(n, vector < bool > (m, 0));
        for (int i = 0 ; i < n; i++)
        {
            for ( int j = 0 ; j < m ; j++)
            {
                if (vis[i][j] or !grid[i][j])
                    continue;
                numOfIslands++;
                dfs(i, j, grid, vis);
            }
        }
        return numOfIslands;
    }
    int minDays(vector<vector<int>>& grid) {
        int numberofIslands = NumberofIslands(grid);
        if (numberofIslands > 1 or numberofIslands == 0)
            return 0;

        // Otherwise check if there is a dimension equal to 1.
        int n = grid.size(), m = grid.back().size();
        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 0 ; j < m ; j++)
            {
                if (grid[i][j] == 0)
                    continue;
                grid[i][j] = 0;
                numberofIslands = NumberofIslands(grid);
                if (numberofIslands > 1 or numberofIslands == 0)
                    return 1;
                grid[i][j] = 1;
            }
        }
        return 2;
    }
};