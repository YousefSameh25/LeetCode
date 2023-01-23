class Solution {
public:
    int dp[1010];
    int solve(int n , int cnt)
    {
        if (n == 1)
            return (cnt & 1);
        int &ret = dp[n];
        if (~ret)
            return ret;
        ret = 0;
        for (int i = 1 ; i * i < n ; i++)
        {
            if (n % i == 0)
                ret |= solve(n - i , cnt + 1);
        }
        return ret;
    }
    bool divisorGame(int n) {
        memset(dp , -1 , sizeof dp);
        return solve(n , 0);
    }
};