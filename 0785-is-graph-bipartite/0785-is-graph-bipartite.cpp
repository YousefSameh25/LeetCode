class Solution {
public:
 int vis[100+10];
    bool dfs (int node , int color , vector<vector<int>>& graph)
    {
        vis[node] = color;
        bool ok = 1;
        for(int ch : graph[node])
        {
             if(vis[ch] == color)
                  ok &= 0;
             else if (vis[ch] == 0)
                 ok &= dfs(ch , 3-color , graph);
        }
        return ok;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        bool ok = 1;
        for (int i = 0 ; i< graph.size();i++)
        {
           if(!vis[i])
              ok &= dfs(i , 1 , graph);
        }
        return ok;
    }
};