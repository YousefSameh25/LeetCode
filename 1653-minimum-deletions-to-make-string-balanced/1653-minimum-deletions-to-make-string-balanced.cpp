class Solution {
public:
    int minimumDeletions(string s) {
        vector < int > preB (s.size() , 0), suffA(s.size(), 0);
        int b = 0;
        for (int i = 0 ; i < s.size() ; i++)
        {
            preB[i] = b;
            b += s[i] == 'b';
        }
        int a = 0;
        for (int i = s.size() - 1 ; i >= 0 ; i--)
        {
            suffA[i] = a;
            a += s[i] == 'a';
        }
        int mn = 1e9;
        for (int i = 0 ; i < s.size() ; i++)
            mn = min(mn, preB[i] + suffA[i]);

        return mn;
    }
};