class Solution {
public:
    vector <int> g[100000 + 10];
    unordered_set < int > bad;
    int dfs (int node , int p)
    {
        int ret = 1;
        for (auto &ch : g[node])
        {
            if (ch == p or bad.count(ch))
                continue;
            ret += dfs (ch , node);
        }
        return ret;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) 
    {    
        for (auto it : edges)
        {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        for (auto it : restricted)
            bad.insert(it);
        
        return dfs (0 , 0);
    }
};