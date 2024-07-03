class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        for (int i = 0 ; i < nums.size(); i++)
        {
            auto it = lower_bound(nums.begin(), nums.end(), (nums[i] + 1) / 2) - nums.begin();
            for (int j = it; j <= i; j++)
                ans = max(ans, nums[i] ^ nums[j]);
        }
        return ans; 
    }
};