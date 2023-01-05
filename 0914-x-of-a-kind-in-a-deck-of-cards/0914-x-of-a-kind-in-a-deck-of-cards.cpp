class Solution {
public:
    bool hasGroupsSizeX(vector<int> & deck)
    {
        int f[10000 + 10] = {};
        for (auto it : deck)
            f[it]++;
        
       int g = 0;
        
        for (int i = 0 ; i <= 1e4 + 9 ; i++)
            g = __gcd(g , f[i]); 
        
        return (g >= 2);
    }
};