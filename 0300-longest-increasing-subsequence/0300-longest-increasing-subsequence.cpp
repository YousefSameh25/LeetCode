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
        //memset (dp , -1 , sizeof dp);
        //return solve(0 , -1, nums);
        
        // Another solution 
        
        vector <int> ans;
        ans.push_back(nums[0]);
        for (int i = 1 ; i < nums.size(); i++)
        {
            if (nums[i] > ans.back())
                ans.push_back(nums[i]);
            else 
            {
                // It the current element smaller than my end so let's use it:
                auto it = lower_bound (ans.begin(), ans.end(), nums[i]);
                /*
                    The lower bound will return the best suitable place 
                    to put nums[i] in it.
                    It also may override the end with smaller value.
                */
                *it = nums[i];
            }
        }
        
        return ans.size();
    }
};