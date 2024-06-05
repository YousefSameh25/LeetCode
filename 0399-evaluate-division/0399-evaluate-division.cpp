class Solution {
public:    
    map <string , vector <pair <string, double>>> G;
    
    double Pro;
    map <string , bool> vis;
    
    void dfs(string st, string& en, double PathPro)
    {
        vis[st] = 1;
        if (st == en)
        {
            Pro = PathPro;
            return;
        }
        
        for (auto child: G[st])
        {
            if (vis[child.first])
                continue;
            dfs(child.first, en, PathPro * child.second);
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, 
            vector<double>& values, vector<vector<string>>& queries) {
        
        int eqN = equations.size();
        for (int i = 0 ; i < eqN; i++)
        {
            G[equations[i][0]].push_back({equations[i][1], values[i]});
            G[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        
        vector <double> ans(queries.size(), -1);

        for (int i = 0 ; i < queries.size(); i++)
        {            
            string st = queries[i][0], en = queries[i][1];
            if (!G.count(st) or !G.count(en))
                continue;
            
            Pro = -1;
            vis.clear();
            dfs(st, en, 1.0);
            ans[i] = Pro;
        }
        return ans;
    }
};