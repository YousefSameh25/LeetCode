class Solution {
public:
    
    int dp[60][26], nn;
    char arr[5] = {'a', 'e', 'i', 'o' , 'u'};
    int solve(int i, char lst)
    {
        if (i == nn)
            return 1;
        
        int &ret = dp[i][lst - 'a'];
        
        if (~ret)
            return ret;
        
        ret = 0;
        
        for (int j = 0 ; j < 5; j++)
        {
            if (lst <= arr[j] or lst == 'z')
                ret += solve(i + 1 , arr[j]);
        }
        
        return ret;
    }
    
    int countVowelStrings(int n) {
        memset (dp , -1 , sizeof(dp));
        nn = n;
        return solve(0, 'z');
    }
};