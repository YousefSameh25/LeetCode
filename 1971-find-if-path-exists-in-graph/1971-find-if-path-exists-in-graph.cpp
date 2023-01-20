class Solution {
public:
    bool vis [200000 + 10];
    vector <int> g [200000 + 10];
    bool dfs (int node , int dest)
    {
        vis[node] = 1;
        bool f = (node == dest);
        for (int child : g[node])
        {
            if (vis[child])
                continue;
            f |= dfs(child , dest);
        }
        return f;
    }
    
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        for (auto &it : edges)
        {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        return dfs(source , destination);
    }
};