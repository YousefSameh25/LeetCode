class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;
        int x = log2(n);
        return (x == log2(n) and (int) log2(n) % 2 == 0);
    }
};