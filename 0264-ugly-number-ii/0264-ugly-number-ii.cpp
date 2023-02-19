class Solution {
public:
    vector <long long> v;
    unordered_map <long long , bool> dp;
    void pre (long long num)
    {
        if (num >= 1e10)
            return;
        if (dp.count(num))
            return;
        if (v.size() == 1670)
            return;

        pre(num * 2);
        pre(num * 3);
        pre(num * 5);
        
        if (not dp.count(num))
            v.push_back(num);
        
        dp[num] = true;
    }
    int nthUglyNumber(int n) 
    {
        pre(1LL);
        sort(v.begin() , v.end());
        return v[n - 1];
    }
};