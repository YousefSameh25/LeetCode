class Solution {
public:
    int dp[1000000];
    int solve (int n)
    {
        if (n == 1)
            return 0;

        if (dp[n] != -1)
            return dp[n];
        
        if (n & 1)
            return dp[n] = solve(n * 3 + 1) + 1;
        
        return dp[n] = solve(n / 2) + 1;
    }
    
    int getKth(int lo, int hi, int k) 
    {
        memset (dp, -1, sizeof dp);
        vector <pair <int, int>> v;
        
        for (int i = lo; i <= hi; i++)
            v.push_back({solve(i), i});
        
        sort(v.begin(), v.end());
        
        return v[k - 1].second;
    }
};