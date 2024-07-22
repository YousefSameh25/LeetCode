class Solution {
public:
    vector < int > vis, rowOrder, colOrder;
    bool Cycle = 0;

    void DFS(int node, vector < int > G[], bool IsRow)
    {
        vis[node] = 1;
        for (auto &child : G[node])
        {
            if (vis[child] == 2)
                continue;
            if (vis[child] == 1)
            {
                Cycle = 1;
                return;
            }
            DFS(child, G, IsRow);
        }
        vis[node] = 2;
        IsRow? rowOrder.push_back(node) : colOrder.push_back(node);
    }

    void solve(int k, vector < vector < int > > & edges, bool IsRow)
    {
        vis.clear();
        vis.resize(k + 1 , 0);
        vector < int > G[k + 1];
        for (auto &it : edges)
            G[it[0]].push_back(it[1]);
        
        for (int i = 1 ; i <= k ; i++)
        {
            if (vis[i])
                continue;
            DFS(i, G, IsRow);
        }
    }


    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) 
    {
        solve(k, rowConditions, 1);
        if (Cycle)
            return {};
        solve(k, colConditions, 0);
        if (Cycle)
            return {};

        reverse(rowOrder.begin(), rowOrder.end());
        reverse(colOrder.begin(), colOrder.end());

        vector < vector < int >> mat(k, vector < int > (k, 0));
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k ; j++)
            {
                if (rowOrder[i] == colOrder[j])
                {
                    mat[i][j] = rowOrder[i];
                    break;
                }
            }
        }
        return mat;
    }
};