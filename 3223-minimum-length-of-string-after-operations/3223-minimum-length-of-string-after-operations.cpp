class Solution {
public:
    int minimumLength(string s) 
    {
        vector < short > v(26, 0);
        int ans = 0;    
        for (int i = 0 ; i < s.size(); i++)
        {
            v[s[i] - 'a']++, ans++;
            if (v[s[i] - 'a'] == 3)
            {
                v[s[i] - 'a'] -= 2;
                ans -= 2;
            }
        }
        return ans;
    }
};