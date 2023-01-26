class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector < int > degree (1e5 + 10 , 0);
        for (auto &e : edges)
        {
            degree[e[0]]++;
            if (degree[e[0]] > 1)
                return e[0];
            degree[e[1]]++;
             if (degree[e[1]] > 1)
                return e[1];
        }
        return 0;
    }
};