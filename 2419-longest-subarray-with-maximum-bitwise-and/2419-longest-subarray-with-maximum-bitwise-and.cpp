class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = -1;
        for (auto it: nums)
            mx = max(mx ,it);

        int len = 0, ans = 0;
        for (int i = 0 ; i < nums.size(); i++)
        {
            if (nums[i] == mx)
                len++;
            else
                len = 0;
            ans = max(len, ans);
        }
        return ans;
    }
};