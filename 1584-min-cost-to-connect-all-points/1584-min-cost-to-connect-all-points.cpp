class Solution {
public:
    struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_parent(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = find_parent(parent[u]);
    }

    bool connect(int u, int v) {
        u = find_parent(u), v = find_parent(v);
        if (u == v)
            return 0;
        if (size[u] < size[v])
            swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        return 1;
    }
};

    int dist(int x1 , int x2 , int y1 , int y2)
    {
        return abs (x1 - x2 ) + abs(y1 - y2);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int idx = 0;
       vector<pair<int,pair<int,int>>> adj;
        for(int i = 0 ; i < points.size(); i++)
        {
             for(int j = i+1 ; j < points.size(); j++)
             {
                 if(i == j)
                     continue;
                 int x1 = points[i][0], y1= points[i][1];
                int x2 = points[j][0], y2 =  points[j][1];
              adj.push_back({dist(x1 ,x2,y1,y2) , {i ,j}});
             }
        }

        sort(adj.begin() , adj.end());
        DSU dsu (points.size());
        int cost = 0;
        for(auto &iter : adj)
        {
            if(dsu.connect(iter.second.first , iter.second.second))
                cost += iter.first;
        }
        return cost;
    }
};