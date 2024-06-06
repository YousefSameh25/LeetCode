class Solution {
public:
    int dp[2][20][20];
    int solve(int t, int l, int r, vector<int>& nums)
    {
        if (l > r)
            return 0;
        
        int &mx = dp[t][l][r];
        
        if (mx != -1e9)
            return mx;
        
        if(!t)
        {
            mx = solve(!t, l + 1, r, nums) + nums[l];
            mx = max(mx , solve(!t, l, r - 1, nums) + nums[r]);
        }
        else 
        {
            mx = solve(!t, l + 1, r, nums) - nums[l];
            mx = min(mx , solve(!t, l, r - 1, nums) - nums[r]);
        }
        return mx;
    }
    
    
    bool predictTheWinner(vector<int>& nums) 
    {
        for (int i = 0 ; i < 2; i++)
            for (int j = 0 ; j < 20; j++)
                for (int k = 0 ; k < 20; k++)
                    dp[i][j][k] = -1e9;

        return solve(0, 0, nums.size() - 1, nums) >= 0;
    }
};