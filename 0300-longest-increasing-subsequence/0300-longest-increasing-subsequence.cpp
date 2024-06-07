class Solution {
public:
    int dp[2500 + 10][2500 + 10];
    int solve(int i, int lastI, vector<int>& nums)
    {
        if (i >= nums.size())
            return 0;
        
        if (lastI != -1 and dp[i][lastI] != -1)
            return dp[i][lastI];
        
        int ret = solve(i + 1, lastI, nums);
        
        if (lastI == -1 or nums[lastI] < nums[i])
            ret = max(ret , solve(i + 1, i, nums) + 1);
        
        if (lastI != -1)
            dp[i][lastI] = ret;
        return ret;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        memset (dp , -1 , sizeof dp);
        return solve(0 , -1, nums);
    }
};