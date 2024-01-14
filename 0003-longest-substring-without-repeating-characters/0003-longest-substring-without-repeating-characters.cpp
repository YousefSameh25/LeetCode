class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int l = 0 , r = 0 , ans = 0;
        map < char , int > mp;
        while (r < s.size())
        {
            if (mp[s[r]] == 0)
                mp[s[r]] = 1 , r++ , ans = max(ans , r - l);
            else 
            {
                while (mp[s[r]])
                {
                    mp[s[l]] = 0;
                    l++;
                }
            }
            //cout << l << " " << r << endl;
        }
        return ans;
    }
};