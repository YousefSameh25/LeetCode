class Solution {
public:
    int dp[20000 + 10];
    int mx = 0;
    int solve(int i, vector <int>& frq, vector<int>& nums)
    {
        if (i > mx)
            return 0;
        
        if (dp[i] != -1)
            return dp[i];
        
        int ret = frq[i] + solve(i + 2, frq, nums);
        
        ret = max(ret, solve(i + 1, frq, nums));
        
        return dp[i] = ret;
    }
    
    
    int deleteAndEarn(vector<int>& nums) 
    {
        vector <int> frq(10000 + 10, 0);
        
        for(auto &it : nums)
            frq[it] += it, mx = max(mx , it);
        
        memset (dp , -1 , sizeof dp);
       
        return solve(0, frq , nums);
    }
};