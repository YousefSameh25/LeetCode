class Solution {
public:
    int dp[500][500][2];
    
    bool solve (int l , int r , int p , vector<int>& piles)
    {
        if (l > r)
            return 0;
        
        int &ret = dp[l][r][p];
        
        if (~ret)
            return ret;
        
        
        int op1 = solve (l + 1 , r , p ^ 1 , piles) + (!p)? piles[l] : - piles[l];
        int op2 = solve (l  , r - 1 , p ^ 1 , piles) + (!p)? piles[l] : - piles[l];
        
        ret = (op1 > 0 or op2 > 0);
        
        return ret;
    }
    
    
    bool stoneGame(vector<int>& piles) {
       memset(dp , -1 , sizeof dp);
       return solve(0 , piles.size() - 1 , 0 , piles);
    }
};