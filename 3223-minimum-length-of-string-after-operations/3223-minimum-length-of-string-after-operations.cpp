class Solution {
public:
    int minimumLength(string s) {
        vector < int > v(26, 0);
        for (int i = 0 ; i < s.size(); i++)
            v[s[i] - 'a']++;
        int ans = 0;
        for (int i = 0 ; i < 26; i++)
        {
            if (!v[i])
                continue;
            ans += (v[i] & 1) ? 1 : 2;
        }        
        return ans;
    }
};