class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long m = 1 , i = 0 , ret = 0;
        while (m <= n)
        {
            if (i < nums.size() and nums[i] <= m)
                m += 1LL * nums[i++];
            else 
                ret++ , m *= 2LL;
        }
        return ret;
    }
};