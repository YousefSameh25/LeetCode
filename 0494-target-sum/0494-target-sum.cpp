class Solution {
private:
    int dp[1000 + 1][2000 + 1];
public:
    int findTargetSumWays(vector<int>& nums, int target, int i = 0, int sum = 0) 
    {
        if (i == nums.size())
            return sum == target;

        if (i == 0)
            memset(dp, -1, sizeof (dp));

        if (dp[i][sum + 1000] != -1)
            return dp[i][sum + 1000];

        return dp[i][sum + 1000] = findTargetSumWays(nums, target, i + 1, sum + nums[i]) +
            findTargetSumWays(nums, target, i + 1, sum - nums[i]);
    }
};