class Solution {
public:
    int kthFactor(int n, int k) {
        vector < int > d;
        for (int i = 1 ; i * i <= n; i++)
        {
            if (n % i)
                continue;
            d.push_back(i);
            if (i != n / i)
                d.push_back(n / i);
        }
        if (k > d.size())
            return -1;
        sort(d.begin(), d.end());
        return d[k -  1];
    }
};