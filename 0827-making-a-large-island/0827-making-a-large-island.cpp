class Solution 
{
public:
    int dir[4];
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
    bool is_valid (int node , int mx)
    {
        return (node >= 0 and node < mx);
    }
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector < int > g;
        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < n ; j++)
                g.push_back(grid[i][j]);
 
        dir[0] = 1 , dir[1] = -1 , dir[2] = n , dir[3] = -n;

        DSU dsu(n * n);
        for (int node = 0 ; node < n * n ; node++)
        {
            if (g[node] == 0)
                continue;
            for (int k = 0 ; k < 4 ; k++)
            {
                int ch = node + dir[k];
                if (not is_valid(ch , n * n))
                    continue;
                if (g[ch] == 0)
                   continue;
                if (dir[k] == 1 and (node + 1) % n == 0)
                    continue;
                if (dir[k] == -1 and node % n == 0)
                    continue;
                 dsu.connect(node , ch);
            }
        }
        
        int mx = 0;
        for (int node = 0 ; node < n * n ; node++)
        {
            set < int > st;
            int sz = 0;
            if (g[node] == 1)
            {
                st.insert(dsu.find_parent(node));
                sz = dsu.size[dsu.find_parent(node)];
            }
            else 
            {
                st.insert(dsu.find_parent(node));
                sz = 1;
            }
            int par_node = dsu.find_parent(node);
            for (int k = 0 ; k < 4 ; k++)
            {
                int ch = node + dir[k];
                if (not is_valid (ch , n * n) or g[ch] == 0)
                    continue;
                if (dir[k] == 1 and (node + 1) % n == 0)
                    continue;
                if (dir[k] == -1 and node % n == 0)
                    continue;
                int par =  dsu.find_parent(ch);
                if (not st.count(par))
                {
                    st.insert(par);
                    sz += dsu.size[par];
                }
            }
            mx = max (mx , sz);
        }
        return mx;
    }
};