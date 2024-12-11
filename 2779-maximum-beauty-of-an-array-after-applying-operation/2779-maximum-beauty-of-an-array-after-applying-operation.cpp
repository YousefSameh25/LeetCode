class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = -100000 - k ; i <= 100000 + k; i++)
        {
            int tar = i;
            int l = lower_bound(nums.begin(), nums.end(), tar - k) - nums.begin();
            int r = upper_bound(nums.begin(), nums.end(), tar + k) - nums.begin();

            ans = max(ans, r - l);
        }
        return ans;
    }
};