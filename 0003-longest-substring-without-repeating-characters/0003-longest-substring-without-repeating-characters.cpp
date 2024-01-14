class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int l = 0 , r = 0 , ans = 0;
        map < char , int > mp;
        while (r < s.size())
        {
            if (mp[s[r]] == 0)
                mp[s[r]] = 1 , ans = max(ans , r - l + 1) , r++;
            else 
            {
                while (mp[s[r]])
                {
                    mp[s[l]] = 0;
                    l++;
                }
            }
        }
        return ans;
    }
};