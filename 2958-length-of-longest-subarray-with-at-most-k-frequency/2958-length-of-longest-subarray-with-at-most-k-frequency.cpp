class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map <int , int> mp;
        
        int l = 0, r = 0, mx = 0;
        while(l < nums.size() and r < nums.size())
        {
            if (mp[nums[r]] + 1 <= k)
            {
                mp[nums[r]]++;
                r++;
            }
            else 
            {
                mp[nums[l]]--;
                l++;
            }
            mx = max(mx , r - l);
        }
        return mx;
    }
};