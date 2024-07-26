class Solution {
public:
    int Dijkstra(int n, int root, int distanceThreshold, vector < pair < int , int>> G[])
    {
        priority_queue < pair < int , int >> pq;
        vector < int > dis(n, 1e9);
        pq.push({0, root});
        dis[root] = 0;

        while(pq.size())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int cost = -it.first;
            if (cost > dis[node] or cost >= distanceThreshold)
                continue;
            
            for (auto &child : G[node])
            {
                if (cost + child.second < dis[child.first])
                {
                    pq.push({-(cost + child.second), child.first});
                    dis[child.first] = cost + child.second;
                }
            }
        }
        int cnt = 0;
        for (int i = 0 ; i < n ; i++)
        {
            if (dis[i] <= distanceThreshold and i != root)
                cnt++;
        }
        return cnt;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector < pair < int , int > > G[n];
        for (auto &it : edges)
        {
            G[it[0]].push_back({it[1], it[2]});
            G[it[1]].push_back({it[0], it[2]});
        }
        int mn = 1e9, node = -1;
        for (int i = 0 ; i < n ; i++)
        {
            int nodes = Dijkstra(n, i, distanceThreshold, G);
            if (nodes < mn)
            {
                node = i;
                mn = nodes;
            }
            else if (nodes == mn)
                node = max(node, i);
        }
        return node;
    }
};