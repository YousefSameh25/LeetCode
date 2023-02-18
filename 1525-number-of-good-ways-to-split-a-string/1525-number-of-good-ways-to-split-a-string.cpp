class Solution {
public:
    int numSplits(string s) {
        vector <int> pre(s.size() , 0) , suf(s.size() , 0) , frq(26 , 0);
        int distinct = 0;
        for (int i = 0 ; i < s.size() ; i++)
        {
            frq[s[i] - 'a']++;
            distinct += (frq[s[i] - 'a'] == 1);
            pre[i] = distinct;
        }
        fill(frq.begin() , frq.end() , 0);
        distinct = 0;
        for (int i = s.size() - 1 ; i >= 0 ; i--)
        {
            frq[s[i] - 'a']++;
            distinct += (frq[s[i] - 'a'] == 1);
            suf[i] = distinct;
        }
        int ret = 0;
        for (int i = 0 ; i < s.size() - 1 ; i++)
            ret += (pre[i] == suf[i + 1]);
        return ret;
    }
};