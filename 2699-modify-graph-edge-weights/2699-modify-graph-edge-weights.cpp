class Solution {
public:

    vector < vector < pair < int , int >>> G;
    int Dijkstra (int src, int dist)
    {
        vector < long long > dis(G.size(), 1e9 + 10);
        dis[src] = 0;
        priority_queue < pair < long long , int >> pq;
        pq.push({0, src});

        while (pq.size())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            long long cost = -it.first;
            if (node == dist)
                break;
            if (cost > dis[node])
                continue;
            for (auto ch : G[node])
            {
                int child = ch.first;
                long long w = ch.second;
                if (w != -1 and dis[child] > w + cost) 
                {
                    dis[child] = w + cost;
                    pq.push({-(w + cost), child});
                }
            }
        }
        return dis[dist];
    }


    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, 
        int source, int destination, int target) {
        G.resize(n);

        vector < int > negEdgsIdx;
        int i = 0;
        for (auto &ed : edges)
        {
            G[ed[0]].push_back({ed[1], ed[2]});
            G[ed[1]].push_back({ed[0], ed[2]});
            if (ed[2] == -1)
            {
                negEdgsIdx.push_back(i);
                ed[2] = target + 1;
            }
            i++;
        }

        long long dis = Dijkstra(source, destination);

        if (dis < target)
            return {};

        if (dis == target)
            return edges;

        for (auto negEdgIdx : negEdgsIdx)
        {
            edges[negEdgIdx][2] = 1;

            G[edges[negEdgIdx][0]].push_back({edges[negEdgIdx][1], edges[negEdgIdx][2]});
            G[edges[negEdgIdx][1]].push_back({edges[negEdgIdx][0], edges[negEdgIdx][2]});

            long long dist = Dijkstra(source, destination);
            if (dist <= target)
            {
                edges[negEdgIdx][2] += target - dist;
                return edges;
            }
        }
        return {};
    }
};