class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target, int i = 0, int sum = 0) 
    {
        if (i == nums.size())
            return sum == target;

        return findTargetSumWays(nums, target, i + 1, sum + nums[i]) +
            findTargetSumWays(nums, target, i + 1, sum - nums[i]);
    }
};