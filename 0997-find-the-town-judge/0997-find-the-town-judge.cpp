class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector <int> in_degree (n + 1 , 0) , out_degree (n + 1 , 0);
        for (auto &it : trust)
        {
            in_degree [it[1]]++;
            out_degree[it[0]]++;
        }
        int c = 0 , ans; 
        for (int i = 1 ; i <= n ; i++)
        {
            if (in_degree[i] == n - 1 and out_degree[i] == 0)
                return i;
        }
        return -1;
    }
};