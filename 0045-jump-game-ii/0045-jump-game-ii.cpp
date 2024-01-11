class Solution {
public:
    int dp[10000];
    int solve(int i, vector<int>& nums)
    {
        if (i == nums.size() - 1)
            return 0;  
        
        int &ret = dp[i];
        
        if (~ret)
            return ret;
        
        ret = 1e9;
        
        for (int j = 1 ; j <= nums[i] ; j++)
        {
            if (i + j < nums.size())
                ret = min(ret , solve(i + j , nums) + 1);
        }
        return ret;
    }
    
    int jump(vector<int>& nums) {
        memset (dp , -1 , sizeof dp);
        return solve(0 , nums);
    }
};