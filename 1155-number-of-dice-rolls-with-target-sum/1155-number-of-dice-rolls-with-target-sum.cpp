class Solution {
public:
    const int MOD = 1e9 + 7;
    int Add(int a, int b)
    {
        a %= MOD;
        b %= MOD;
        return (a + b) % MOD;
    }
    
    int dp[31][1001], K;
    int solve (int i, int target)
    {
        if (!i)
            return target == 0;
        
        
        int &ways = dp[i][target];
        
        if (~ways)
            return ways;
        
        ways = 0;
        
        for (int f = 1; f <= K and f <= target; f++)
            ways = Add(ways, solve(i - 1, target - f));
        
        return ways;
    }
     
    int numRollsToTarget(int n, int k, int target) {
        K = k;
        memset (dp , -1 , sizeof dp);
        return solve(n , target);
    }
};