class Solution {
public:
    vector < long long > v;
    unordered_set < long long > dp;
    void solve(long long num, int n)
    {
        if (num >= INT_MAX)
            return;
        if (dp.count(num))
            return;
        v.push_back(num);
        solve(num * 2, n);
        solve(num * 3, n);
        solve(num * 5, n);
        dp.insert(num);
    }
    int nthUglyNumber(int n) {
        solve(1LL, n);
        sort(v.begin(), v.end());
        return v[n - 1];
    }
};