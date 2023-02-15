class Solution {
public:

    vector<pair<int, int> > g[100 + 10];
    long long dist[100 + 10];
    void Dijkstra(int src) {
        for (int i = 0; i <= 100 + 9; i++)
            dist[i] = 1e17;
        dist[src] = 0;

        priority_queue<pair<int, int> > pq;
        pq.push({0, src});
        while (!pq.empty()) {
            int node = pq.top().second, curcost = -pq.top().first;
            pq.pop();
            if (dist[node] < curcost)
                continue;
            for (auto ch: g[node]) {
                int newcost = curcost + ch.second;
                if (newcost < dist[ch.first]) {
                    dist[ch.first] = newcost;
                    pq.push({-newcost, ch.first});
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(auto it : times )
            g[it[0]].emplace_back(it[1] , it[2]);

        Dijkstra(k);
        long long mx =  -1;
        for(int i = 1; i <= n ; i++)
            mx = max ( mx , dist[i]);
        
        return (mx == 1e17? -1 : mx);
    }
};