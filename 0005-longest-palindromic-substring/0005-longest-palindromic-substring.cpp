class Solution {
public:
    bool SubIsPalindrome (string &s , int st , int len)
    {
        int l = st , r = l + len - 1;
        while(l < r)
        {
            if (s[l] != s[r])
                return false;
            l++, r--;
        }
        return true;
    }
    string longestPalindrome(string s) 
    {
        int n = s.size() , ans = 0;
        string sans = "";
        for (int i = 0 ; i < n ; i++) 
        {
            int l = 1, r = n - i;
            while (l <= r)
            {
                if (SubIsPalindrome(s, i , l) and l >= ans)
                {
                    sans = s.substr(i , l);
                    ans = l;
                }
                l++;
            }
        }
        return sans;
    }
};