class Solution {
public:
    int minDifference(vector<int>& nums) {
        
        if (nums.size() <= 3)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int r = 3, ans = 2e9;
        
        while(r >= 0)
        {
            int l = 3 - r; 
            ans = min(ans, nums[nums.size() - r - 1] - nums[0 + l]);
            r--;
        }
        
        return ans;
    }
};