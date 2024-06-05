class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        
        double half = myPow(x , n / 2);
        
        
        half *= half;
        
        if (n & 1)
        {
            if (n > 0)
                half *= x;
            else 
                half *= 1 / x;
        }
        
        return half;
    }
};