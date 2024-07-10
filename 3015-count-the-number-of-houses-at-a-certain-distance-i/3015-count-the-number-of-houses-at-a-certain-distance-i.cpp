class Solution {
public:
    
    void BFS (int n, int x , int y , int cur, vector < int > & ans)
    {
        vector < int > G[n];
        // Build Graph
        for (int i = 0 ; i < n - 1 ; i++)
        {
            G[i].push_back(i + 1);
            G[i + 1].push_back(i);
        }
        
        G[x - 1].push_back(y - 1);
        G[y - 1].push_back(x - 1);
   
        vector < int > dis(n, 1e9);
        dis[cur] = 0;
        queue < int > q;
        q.push(cur);
        while(q.size())
        {
            auto node = q.front();
            q.pop();
            for ( auto child : G[node])
            {
                if (dis[child] != 1e9)
                    continue;
                dis[child] = dis[node] + 1;
                q.push(child);
            }
        }
        
        for (auto it : dis)
        {
            if (it != 0 and it != 1e9)
                ans[it - 1]++;
        }
    }
    
    
    vector<int> countOfPairs(int n, int x, int y) {
        vector < int > ans(n , 0);
        for (int i = 0 ; i < n ; i++)
            BFS(n, x, y, i, ans);
        return ans;
    }
};