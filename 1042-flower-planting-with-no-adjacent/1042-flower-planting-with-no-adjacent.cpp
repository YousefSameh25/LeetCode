class Solution {
public:
    int col[2 * 10000 + 10];
    vector <int> g[2 * 10000 + 10];
    void dfs (int node)
    {
        bitset < 5 > valid;
        valid.set();

        for (auto child : g[node])
            valid[col[child]] = 0;
        
        for (int i = 1 ; i <= 4 ; i++)
        {
            if (not valid[i])
                continue;
            col[node] = i;
            break;
        }

        for (auto ch : g[node])
        {
            if (col[ch])
                continue;
            dfs(ch);
        }
    }
    vector <int> gardenNoAdj(int n, vector<vector<int>>& paths) 
    {
        for (auto &it : paths)
        {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        for (int i = 1 ; i <= n; i++)
        {
            if (col[i] == 0)
                dfs (i);
        }
        vector < int > ans;
        for (int  i = 1 ; i <= n ; i++)
            ans.push_back(col[i]);
        return ans;
    }
};