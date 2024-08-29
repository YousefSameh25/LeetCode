class Solution {
public:
    vector < vector < bool > > vis;
    vector < vector < pair < int , int > > > rows, colus;
    int dfs (int r, int c)
    {
        vis[r][c] = 1;
        int ans = 1;

        for (auto & it : rows[r])
        {
            if (vis[it.first][it.second])
                continue;
            ans += dfs(it.first, it.second);
        }
        for (auto & it : colus[c])
        {
            if (vis[it.first][it.second])
                continue;
            ans += dfs(it.first, it.second);
        }
        return ans;
    }
    int removeStones(vector<vector<int>>& stones) 
    {
        vis.resize(10000 + 1, vector <bool> (10000 + 1, 0));
        rows.resize(10000 + 1), colus.resize(10000 + 1);
        for (int i = 0 ; i < stones.size(); i++)
        {
            int r = stones[i][0], c = stones[i][1];
            rows[r].push_back({r, c});
            colus[c].push_back({r, c});
        }

        int ans = 0;
        for (int i = 0 ; i < stones.size(); i++)
        {
            if (vis[stones[i][0]][stones[i][1]])
                continue;
            ans += dfs(stones[i][0], stones[i][1]) - 1;
        }
        return ans;
    }
};