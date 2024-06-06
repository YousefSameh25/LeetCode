class Solution {
public:
    
    int solve(int t, int l, int r, vector<int>& nums)
    {
        if (l > r)
            return 0;
        
        int mx;
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
    
    
    bool predictTheWinner(vector<int>& nums) {
        return solve(0, 0, nums.size() - 1, nums) >= 0;
    }
};