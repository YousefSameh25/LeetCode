class Solution {
public:
    int minimumLength(string s) {
        vector < int > v(26, 0);
        int ans = 0;    
        for (int i = 0 ; i < s.size(); i++)
        {
            if (v[s[i] - 'a'] == 2)
            {
                v[s[i] - 'a']--;
                ans--;
            }
            else
            {
                v[s[i] - 'a']++;
                ans++;
            }
        }
         
        return ans;
    }
};