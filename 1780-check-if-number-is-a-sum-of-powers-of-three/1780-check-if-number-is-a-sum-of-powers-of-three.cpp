class Solution {
public:
    bool checkPowersOfThree(int n) {
        int t = pow(3 , 15);
        while(t)
        {
            if (t <= n)
                n -= t;
            t /= 3;
        }
        return (n == 0);
    }
};