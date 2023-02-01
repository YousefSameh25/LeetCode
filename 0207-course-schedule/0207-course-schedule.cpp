class Solution {
public:
    int color[5 * 1000 + 10];
    vector <int> g[5 * 1000 + 0];
    bool dfs (int node ,int col)
    {
        color[node] = col;
        bool valid = 1;
        for (auto ch : g[node])
        {
            if (color[ch] == 0)
                valid &= dfs(ch , 1);
            else if (color[ch] == 1)
                valid = 0;
        }
        color[node] = 2;
        return valid;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto &it : prerequisites)
            g[it[0]].push_back(it[1]);
        bool ret = 1;
        for (int i = 0 ; i < numCourses ; i++)
        {
            if (color[i] == 0)
                ret &= dfs(i , 1);
        }
        return ret;
    }
};