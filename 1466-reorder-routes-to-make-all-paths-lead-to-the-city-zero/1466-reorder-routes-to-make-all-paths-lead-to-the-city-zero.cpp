class Solution {
public:
    vector <int> g[5 * 10000 + 10];
    set <vector <int>> st;
    int vis[5 * 10000 + 10] , ans = 0;
    void dfs (int node)
    {
        vis[node] = 1;
        for (auto ch : g[node])
        {
            if (vis[ch])
                continue;
            if (not st.count({ch , node}))
                ans++;
            dfs(ch);
        }
    }
    
    
    int minReorder(int n, vector<vector<int>>& connections) 
    {

        for (auto &it : connections)
        {
            st.insert(it);
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        dfs (0);
        return ans;
    }
};