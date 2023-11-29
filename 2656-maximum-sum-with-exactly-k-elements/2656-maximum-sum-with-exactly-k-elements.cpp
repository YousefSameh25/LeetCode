class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        int r = mx + k - 1;
        r = r * (r + 1) / 2;
        int l = mx - 1;
        l = l * (l + 1) / 2;
        return r - l;
    }
};