class Solution {
public:
    vector <int> g[5 * 10000 + 10];
    set <vector <int>> st;
    int vis[5 * 10000 + 10];
    int dfs (int node)
    {
        vis[node] = 1;
        int ans = 0;
        for (auto ch : g[node])
        {
            if (vis[ch])
                continue;
            if (not st.count({ch , node}))
                ans++;
            ans += dfs(ch);
        }
        return ans;
    }
    
    
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        for (auto &it : connections)
        {
            st.insert(it);
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        return dfs(0);
    }
};