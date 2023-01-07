class Solution {
    
public:
    int dp[101][10001];
    bool solve (int i , int j , string &s , string& t)
    {
        if (i == s.size())
            return 1;
        
        if (j == t.size())
            return 0;
        
        int &ans = dp[i][j];
        
        if (~ans)
            return ans;
        
        ans = 0;
        
        if (s[i] == t[j])
            ans |= solve (i + 1 , j + 1 , s , t);
        
        else 
            ans |= solve (i , j + 1 , s , t);

        return ans;     
    }
    bool isSubsequence(string s, string t) {
        memset (dp , -1 , sizeof dp);
        return solve (0 , 0 , s , t);
    }
};