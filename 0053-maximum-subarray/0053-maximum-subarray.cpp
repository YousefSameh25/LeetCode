class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = -1e9 , sum = 0;
        for (auto it : nums)
        {
            sum = max (it , sum + it);
            mx = max(mx , sum);
        }
        return mx;
    }
};