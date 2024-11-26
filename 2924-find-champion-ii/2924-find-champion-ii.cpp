class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) 
    {
        bool indegree[n];
        memset (indegree, 0, sizeof(indegree));
        for (auto ed : edges)
            indegree[ed[1]] = 1;

        int champion = -1, cnt = 0;
        for (int i = 0 ; i < n; i++)
        {
            if (!indegree[i])
            {
                champion = i;
                cnt++;
            }
        }
        if (cnt > 1)
            return -1;
        return champion;
    }
};