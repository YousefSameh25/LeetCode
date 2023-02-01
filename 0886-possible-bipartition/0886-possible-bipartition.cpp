class Solution {
public:
    vector <int> g[10000 + 10];
    int t[10000 + 10];
    bool dfs (int node , int type)
    {
        t[node] = type;
        bool can = 1;
        for (auto ch : g[node])
        {
            if (t[ch] == 0)
                can &= dfs (ch , 3 - type);
            else 
                can &= (t[node] != t[ch]);
        }
        return can;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        for (auto &it : dislikes)
        {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        bool ret = 1;
        for (int i = 1 ; i <= n ; i++)
        {
            if (t[i] == 0)
                ret &= dfs(i , 1);
        }
        return ret;
    }
};