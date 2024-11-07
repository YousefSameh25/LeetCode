class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int n = nums.size();
        vector < int > suf(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            suf[i] |= nums[i];
        }

        int zor = 0;
        for (int i = 0 ; i < n; i++)
        {
            zor ^= (nums[i] & suf[i]);
        }
        return zor;
    }
};