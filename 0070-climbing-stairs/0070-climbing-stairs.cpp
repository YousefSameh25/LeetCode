class Solution {
public:
    int dp[50];
    int ways (int cur ,int end)
    {
        if (cur == end)
            return 1;
        if (cur > end)
            return 0;
        int &ret = dp[cur];
        if (~ret)
            return ret;
        ret = ways(cur + 1 ,end) + ways (cur + 2 , end);
        return ret;
    }
    int climbStairs(int n) {
        memset (dp , -1 , sizeof dp);
        return ways(0 , n);
    }
};