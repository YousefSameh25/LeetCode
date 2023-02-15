class Solution {
public:
    
    int vis[100000 + 10] , cy = 0;
    vector < int > g[100000 + 10];
    string color;
    vector <int> dp[100000 + 10];
    void dfs (int node)
    {
        vis[node] = 1;
        for (auto ch : g[node])
        {
            if (vis[ch] == 1)
                cy = 1;
            else if (not vis [ch])
                dfs (ch);
        }
        vis[node] = 2;
    }
    
    
    vector <int> solve (int node)
    {
      if (dp[node].size())
          return dp[node];
      
        dp[node].resize(26 , 0);    
        
        for (auto ch : g[node])
        {
            vector <int> t = solve (ch);
            for (int i = 0 ; i < 26 ; i++)
                dp[node][i] = max(dp[node][i] , t[i]);
        }
        
        dp[node][color[node] - 'a']++;
          
        return dp[node];
    }
    
    
    
    int largestPathValue(string colors, vector<vector<int>>& edges) 
    {
  
        for (auto it : edges)
            g[it[0]].push_back(it[1]);
        
        for (int i = 0 ; i < colors.size() ; i++)   
        {
            dfs (i);
            if (cy)
                return -1;
        }
        
         color = colors;
             
         int mx = 0;
         for (int i = 0 ; i < colors.size() ; i++)
         {
             for (auto it : solve (i))
                 mx = max(mx , it);
         }

        return mx;
    }
};