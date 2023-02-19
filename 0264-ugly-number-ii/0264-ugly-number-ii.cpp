class Solution {
public:
    set <long long> st;
    map <long long , bool> dp;
    void pre (long long num)
    {
        if (num >= 1e10)
            return;
        if (dp.count(num))
            return;
        st.insert(num);
        pre(num * 2);
        pre(num * 3);
        pre(num * 5);
        dp[num] = true;
    }
    int nthUglyNumber(int n) 
    {
        pre(1LL);
        int i = 0;
        for (auto & it : st)
        {
            i++;
            if (i == n)
                return it;
        }
        return 0;
    }
};