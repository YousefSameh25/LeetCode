class Solution {
public:
    bool vis[500][500];
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    bool valid(int i, int j, int n, int m)
    {
        return i >=0 and i < n and j >= 0 and j < m;
    }
    bool dfs (int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        vis[i][j] = 1;
        bool ans = (grid1[i][j] + grid2[i][j] == 2);
        if (!ans)
            return ans;

        for (int c = 0 ; c < 4; c++)
        {
            int ic = i + dx[c], jc = j + dy[c];
            if (!valid(ic, jc, grid1.size(), grid2.back().size()))
                continue;
            if (!grid1[ic][jc] and grid2[ic][jc])
                return 0;
            if (vis[ic][jc] or !grid2[ic][jc])
                continue;
            
            ans &= dfs(ic, jc, grid1, grid2);
        }
        return ans;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1.back().size(), com = 0;
        for (int i = 0 ;  i < n ; i++)
        {
            for (int j = 0 ; j < m; j++)
            {
                if (grid2[i][j] == 0 or vis[i][j])
                    continue;
                com += dfs(i, j, grid1, grid2);
            }
        }
        return com;
    }
};