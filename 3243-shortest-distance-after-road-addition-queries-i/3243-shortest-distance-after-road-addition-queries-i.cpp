class Solution {
public:

    int BFS (int n, vector < vector < int > >& G)
    {
        queue < int > q;
        vector < int > lvl (n, -1);

        q.push(0);
        lvl[0] = 0;

        while(q.size())
        {
            auto node = q.front();
            q.pop();

            for (auto& child : G[node])
            {
                if (lvl[child] != -1)
                    continue;
                q.push(child);
                lvl[child] = lvl[node] + 1;
            }
        }
        return lvl[n - 1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) 
    {
        vector < int > ans;
        vector < vector < int > > G(n);

        for (int node = 0; node < n - 1; node++)
            G[node].push_back(node + 1);

        for (auto &edge: queries)
        {
            G[edge[0]].push_back(edge[1]);
            ans.push_back(BFS(n, G));
        }
        return ans;
    }
};