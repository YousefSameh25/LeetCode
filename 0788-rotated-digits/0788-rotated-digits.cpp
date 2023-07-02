class Solution {
public:
    
    bool rotatable (int d)
    {
        return (d != 4 and d != 3 and d != 7);
    }
    
    bool different (int d)
    {
        return (d == 2 or d == 5 or d == 6 or d == 9);
    }
    
    bool good (int x)
    {
        bool can_rotate = 1 , will_be_diff = 0;
        while (x)
        {
            can_rotate &= rotatable (x % 10);
            will_be_diff |= different (x % 10);
            x /= 10;
        }
        return can_rotate and will_be_diff;
    }
    
    
    int rotatedDigits(int n) {
        
        int ans = 0;
        for ( int i = 1 ; i <= n ; i++)
        {
            if (good(i))
                ans++;
        }
        return ans;
    }
};