class Solution {
public:
    int kthFactor(int n, int k) {
        for (int i = 1 ; i * i < n; i++)
        {
            if (n % i)
                continue;
            if (--k == 0)
                return i;
        }

        for (int i = sqrt(n); i <= n; i++)
        {
            if (n % i)
                continue;
            if (--k == 0)
                return i;
        }
        return -1;
    }
};