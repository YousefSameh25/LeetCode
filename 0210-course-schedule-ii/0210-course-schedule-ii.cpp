class Solution {
public:
    vector <int> ans;
    int vis[2 * 1000 + 10];
    vector <int> g[2 * 1000 + 10];
    bool dfs (int node)
    {
        vis[node] = 1;
        bool valid = 1;
        for (auto ch : g[node])
        {
            if (vis[ch] == 0)
                valid &= dfs (ch);
            else if (vis[ch] == 1)
                valid = 0;
        }
        ans.push_back(node);
        vis[node] = 2;
        return valid;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        for (auto & it : prerequisites)
            g[it[0]].push_back(it[1]);
        
        bool va = 1;
        for (int i = 0 ; i < numCourses ; i++)
        {
            if (vis[i] == 0)
                va &= dfs(i);
        }
        if (not va)
            ans.clear();
        
        return ans;
    }
};