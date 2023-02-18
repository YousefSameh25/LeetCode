class Solution {
public:
    int dp[300 + 10][5000 + 10];
    int solve (int i , int m , vector <int> &coins)
    {
        if (i == coins.size())
            return (m == 0);
        
        
        int &ret = dp[i][m];
        
        if (~ret)
            return ret;
        
        ret = 0;
        
        if (m >= coins[i])
            ret += solve (i , m - coins[i] , coins);
        
         ret += solve(i + 1 , m , coins);
        
        return ret;
    }
    int change(int amount, vector<int>& coins) {
        memset (dp , -1 , sizeof dp);
        sort(coins.begin() , coins.end());
        reverse (coins.begin() , coins.end());
        return solve(0 , amount , coins);
    }
};