class Solution {
public:
    vector <pair<int , int>> g[110];
    int vis [110][3];
    int lvl [110];
    
    void bfs ()
    {
        queue <  pair < int , pair < int , int > > > q;
        q.push ({0 , {0 , 0}});
        lvl[0] = 0;
        while(q.size())
        {
            auto it = q.front();
            q.pop();
            for (auto child : g[it.first])
            {
                if (vis[child.first][child.second])
                    continue;
                
                if (it.second.first != child.second)
                {
                    if (lvl[child.first] == 1e9)
                       lvl [child.first] = it.second.second + 1;
                    vis [child.first][child.second] = 1;
                    q.push({child.first , { child.second , it.second.second + 1 }});
                }
            }
        }
    }
    
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        for (int i = 0 ; i <= n ; i++)
            lvl[i] = 1e9;    
        
        for(auto iter : redEdges)
            g[iter[0]].push_back({iter[1] , 1});
        for(auto iter : blueEdges)
            g[iter[0]].push_back({iter[1] , 2});
        
        bfs();
        
        vector < int > ans;
        for (int i = 0 ; i < n ; i++)
            (lvl[i] == 1e9)? ans.push_back(-1) : ans.push_back(lvl[i]);
        
        return ans;
     
    }
};