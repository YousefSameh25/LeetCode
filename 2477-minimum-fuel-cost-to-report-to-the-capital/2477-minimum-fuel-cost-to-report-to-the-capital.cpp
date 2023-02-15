class Solution {
public:
    int cnt[100000 + 10];
    vector < int > g [100000 + 10];
    int dfs (int node , int par , int seats)
    {
        int c = 1;
        for (auto child : g[node])
        {
            if (child == par)
                continue;
            c += dfs (child , node , seats);
        }
        return cnt[node] = c;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) 
    {
        for (auto &it : roads)
        {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        dfs (0 , 0 , seats);
        long long ret = 0;
        for (int i = 1 ; i <= roads.size() ; i++)
            ret += 1LL * (cnt[i] + seats - 1) / seats;
  
        return ret;
    }
};