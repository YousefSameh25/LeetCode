class Solution {
public:
    vector<int> minOperations(string s) {
        int n = s.size();
        vector < int > pre(n, 0), suf(n, 0);
        int cnt = 0;
        for (auto it : s)
            cnt += it == '1';

        int sumPre = 0;
        for (int i = 0 ; i < n; i++)
        {
            pre[i] = sumPre;
            sumPre += s[i] == '1'? i : 0;
        }
        int sumSuf = 0;
        for (int i = n - 1 ; i >= 0; i--)
        {
            suf[i] = sumSuf;
            sumSuf += s[i] == '1'? i : 0;
        }

        vector < int > ans(n, 0);
        int preCnt = 0;
        for (int i = 0 ; i < n ; i++)
        {
            ans[i] += preCnt * i - pre[i];
            preCnt += s[i] == '1';
            ans[i] += suf[i] - i * (cnt - preCnt);
        }
        return ans;
    }
};