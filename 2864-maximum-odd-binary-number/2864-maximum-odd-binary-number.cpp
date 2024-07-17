class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = count(s.begin(), s.end(), '1');
        string ans(s.size(), '0');

        ans[ans.size() - 1] = '1';

        for (int i = 0 ; i < cnt - 1; i++)
            ans[i] = '1';

        return ans;
    }
};