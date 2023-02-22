class Solution {
public:
    bool isPowerOfThree(int n) {
        long long val = 1;
        while(val < n and val * 3 < INT_MAX)
            val *= 3;
        return (val == n);
    }
};