class Solution {
public:
    map < pair < vector < int > , int > , int > dp;
    
    int solve (int idx , vector < int > cur , vector <int> &p , vector<vector<int>>& s)
    {
        if (idx == s.size())
        {
            int rem = 0;
            for (int i = 0 ; i < p.size() ; i++)
                rem += p[i] * cur[i];
            return rem;
        }
        
        
        if (dp.count({cur , idx}))
            return dp[{cur , idx}];
        
        dp[{cur , idx}] = 1e9;
        
        
        bool can = 1;
        
        for (int i = 0 ; i < p.size() ; i++)
            can &= (cur[i] >= s[idx][i]);
        
        if (can)
        {
            vector < int > tmp = cur;
            
            for (int i = 0 ; i < p.size() ; i++)
                tmp[i] -= s[idx][i];
            
           dp[{cur , idx}] = solve (idx , tmp , p , s) + s[idx][p.size()];
        }
        
         dp[{cur , idx}] = min ( dp[{cur , idx}] , solve (idx + 1 , cur , p , s));
        
        return  dp[{cur , idx}];
    }
    
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) 
    {
        return solve(0 , needs , price , special);
    }
};