class Solution {
public:
    
    int dp[60][26], nn;
    char arr[5] = {'a', 'e', 'i', 'o' , 'u'};
    int solve(int i, char lst)
    {
        
        if (i == nn)
            return 1;
        
        int ret = 0;
        
        for (int j = 0 ; j < 5; j++)
        {
            if (lst <= arr[j] or lst == '*')
                ret += solve(i + 1 , arr[j]);
        }
        
        return ret;
        
    }
    
    int countVowelStrings(int n) {
        nn = n;
        return solve(0, '*');
    }
};