class Solution {
public:
    vector <int> g [500 + 10];
    int dp_mn[500 + 10];
    // Gets the value of lowest quiet
    int dfs (int node ,vector<int>& quiet)
    {
        if (dp_mn[node] != -1)
            return dp_mn[node];
        
        dp_mn[node] = quiet[node];
        
        for (auto ch : g[node])
        {
            dp_mn[node] = min (dp_mn[node] , dfs(ch , quiet));
        }
        
        return dp_mn[node];
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) 
    {
        for (auto& it : richer)
            g[it[1]].push_back(it[0]);
        
        map <int , int> mp;
        for (int i = 0 ; i < quiet.size() ; i++)
            mp[quiet[i]] = i;
        
        memset (dp_mn , -1 , sizeof dp_mn);
        vector <int> ret (quiet.size());
        for (int i = 0 ; i < quiet.size() ; i++)  {
            ret[i] = mp[dfs (i , quiet)];
        }
        return ret;
    }
};