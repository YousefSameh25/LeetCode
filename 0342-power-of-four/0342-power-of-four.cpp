class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;
        int x = log2(abs(n));
        return (x == log2(abs(n)) and (int)log2(abs(n)) % 2 == 0);
    }
};