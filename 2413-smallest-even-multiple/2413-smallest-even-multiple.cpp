class Solution {
public:
    int smallestEvenMultiple(int n) {
        if (n & 1)
            return 2 * n;
        return n;
    }
};