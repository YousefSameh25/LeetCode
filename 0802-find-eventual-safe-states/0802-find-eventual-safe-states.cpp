class Solution {
public:
    int vis[10000+10] , valid[10000+10];
    //  valid =1 not included
    bool dfs(int node  , vector<vector<int>>& graph)
    {
      // when solve problem and return to unclosed problem
        if(vis[node] == 1) 
            return 0; 
        // approach dp (mimozation)
        if (valid[node] != -1)
            return valid[node];
        int ret = 1;
        vis[node] = 1; // mark problem unsolved (open)
        for(int i : graph[node])
            ret &= dfs(i,graph);

        vis[node] = 2; // mark problem is solved
        return valid[node] = ret; 
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        
        memset(valid , -1, sizeof valid);
        
        vector<int> ans;
        
        for(int i = 0 ; i< n;i++)
             dfs(i , graph);
        
        for(int i = 0 ; i< n;i++)
        {
            if(valid[i])
                ans.push_back(i);
        }
        return ans;

    }
};