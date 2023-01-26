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
    bool equationsPossible(vector<string>& equations) 
    {
        DSU dsu (26);
        for (auto &eq : equations)
        {
            if (eq[1] == '=')
                dsu.connect(eq[0] - 'a' , eq[3] - 'a');
        }
          for (auto &eq : equations)
        {
            if (eq[1] == '!')
            {
                if (dsu.find_parent(eq[0] - 'a') == dsu.find_parent(eq[3] - 'a'))
                    return false;
            }
        }
        return true;
    }
};