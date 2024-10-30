class Solution {
public:
    vector < vector < int >> dp;
    int R (int i, int prvi, vector<int>& nums)
    {
        if (i >= nums.size())
            return 0;
        int &ret = dp[i][prvi];
        if (~ret)
            return ret; 
        ret = R(i + 1, prvi, nums);
        if (nums[prvi] > nums[i])
            ret = max(ret, 1 + R(i + 1, i, nums));
        return ret;
    }
    int L (int i, int prvi, vector<int>& nums)
    {
        if (i < 0)
            return 0;
        int &ret = dp[i][prvi];
        if (~ret)
            return ret; 
        ret = L(i - 1, prvi, nums);
        if (nums[prvi] > nums[i])
            ret = max(ret, 1 + L(i - 1, i, nums));
        return ret;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        dp.resize(nums.size(), vector < int > (nums.size(), -1));
        int mx = 0;
        for (int i = 1 ; i < nums.size() - 1; i++)
        {
            if(R(i + 1, i, nums) and L(i - 1, i, nums))
                mx = max(mx, R(i + 1, i, nums) + L(i - 1, i, nums) + 1);
        }
        return nums.size() - mx;
    }
};