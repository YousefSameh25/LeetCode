class Solution {
public:
    /*
    - i -> means I have moved i distance from the begin.
    - r -> means I have a reminder r after my travel.
    When I draw the tree I found that there is an overlap with the state (i, r).
    */
    
    vector<vector<int>> dp;
    int Solve(int i, int r, vector<vector<int>>& piles)
    {
        if (i == piles.size() or !r)
            return 0;
        
        if (dp[i][r] != -1)
            return dp[i][r];
        
        int ans = Solve(i + 1, r, piles);
        
        for (int j = 1 ; j <= r and j <= piles[i].size(); j++)
        {
            ans = max(ans , Solve(i + 1, r - j, piles) +  piles[i][j - 1]);
        }
        return dp[i][r] = ans;
    }
    
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) 
    {

        int n = piles.size();
        dp.resize(n, vector <int>(k + 1, -1));
            
        for (int i = 0 ; i < n ; i++)
            for (int j = 1 ; j < piles[i].size(); j++)
                piles[i][j] += piles[i][j - 1];
        
        return Solve(0, k, piles);
    }
};