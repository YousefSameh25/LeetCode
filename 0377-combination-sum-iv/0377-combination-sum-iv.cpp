class Solution {
public:
    int dp[1000 + 1];
    int solve(vector <int> &nums, int target)
    {
        if (target == 0)
            return 1;
        
        int &ret = dp[target];
        
        if (ret != -1)
            return ret;
        
        ret = 0;
        for (int i = 0; i < nums.size() and target >= nums[i] ; i++)
            ret += solve(nums, target - nums[i]);
        
        return ret;
    }
    
    
    int combinationSum4(vector<int>& nums, int target) {
        memset (dp, -1, sizeof dp);
        sort(nums.begin(), nums.end());
        return solve(nums, target);
    }
};