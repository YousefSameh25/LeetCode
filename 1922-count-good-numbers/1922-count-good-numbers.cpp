class Solution {
public:
    const int MOD = 1e9 + 7;
    int Pro(int a, int b)
    {
        a %= MOD;
        b %= MOD;
        return (1LL * a * b) % MOD;
    }
    
    int fast_power (int b, long long p)
    {
        if (p == 0)
            return 1;
        
        int half = fast_power(b, p / 2);
        
        half = Pro(half, half);
        
        if (p & 1)
            half = Pro(half, b);
        
        return half;
    }
    
    int countGoodNumbers(long long n) {
        /*
            [XXX]
            even = 3 - (3 / 2) = 2
            odd = 3 / 2 = 1
            
            even -> [XX] -> [5*5]
            odd -> [X] -> [4]
            
            ans = 100
            
            we need fast power.
        */
        
        long long odd = n / 2;
        long long even = n - odd;
        
        return Pro(fast_power(5, even), fast_power(4, odd));
    }
};