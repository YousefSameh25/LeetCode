class Solution {
public:
    int col[2 * 10000 + 10];
    vector <int> g[2 * 10000 + 10];
    void dfs (int node)
    {
        vector < int > tmp = {1 , 2 , 3 , 4}; 
        set < int > st (tmp.begin() , tmp.end());
        for (auto child : g[node])
            st.erase(col[child]);
        col[node] = *st.begin();
        for (auto ch : g[node])
        {
            if (col[ch])
                continue;
            dfs(ch);
        }
    }
    vector <int> gardenNoAdj(int n, vector<vector<int>>& paths) 
    {
        for (auto &it : paths)
        {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        for (int i = 1 ; i <= n; i++)
        {
            if (col[i] == 0)
                dfs (i);
        }
        vector < int > ans;
        for (int  i = 1 ; i <= n ; i++)
            ans.push_back(col[i]);
        return ans;
    }
};