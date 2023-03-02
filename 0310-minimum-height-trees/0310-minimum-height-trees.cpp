class Solution {
public:
    int vis[20000+10],lvl[3][20000+10];
   int mx = 0;
    void bfs (int node , vector<vector<int>>&adj , int f)
    {
        queue<int> q;
        q.push(node);
        vis[node] =1 ;
        lvl[f][node] = 1;
        mx = node ;
        while(q.size())
        {
            int cur_node = q.front();
            q.pop();
            mx = cur_node;
            for(int ch : adj[cur_node])
            {
                if(!vis[ch])
                {
                    lvl[f][ch] = lvl[f][cur_node] +1 ;
                    vis[ch] = 1;
                    q.push(ch);
                }
            }
        }

    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(20000+10);
        for(auto it : edges)
            adj[it[0]].push_back(it[1]),adj[it[1]].push_back(it[0]);

        bfs(0 ,adj , 0);

        memset(vis , 0 , sizeof vis);
        bfs(mx , adj,1);

        memset(vis , 0 , sizeof vis);
        bfs(mx , adj,2);
        int mx_lvl = 0;
        for(int i = 0 ; i< n;i++)
           mx_lvl = max (mx_lvl , lvl[1][i]);
        vector<int> ans;
        // cout << lvl[5];
        for(int i = 0 ; i < n;i++)
        {
            if (max(lvl[1][i] , lvl[2][i]) == mx_lvl / 2 + 1)
                ans.push_back(i);
        }
        return ans;
    }
};