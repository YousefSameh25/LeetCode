class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k)     {
        
        map <int , priority_queue<int>> mp;
        
        for (auto e : edges)
        {
            mp[e[0]].push(vals[e[1]]);
            mp[e[1]].push(vals[e[0]]);
        }
        
        int mx = -2e9;
        for (int i = 0 ; i < vals.size() ; i++)
        {
            int tempk = k, sum = vals[i];
            while(tempk-- and mp[i].size() and mp[i].top() > 0)
            {
                sum += mp[i].top();
                mp[i].pop();
            }
            mx = max(mx , sum);
        }     
        return mx;   
    }
};