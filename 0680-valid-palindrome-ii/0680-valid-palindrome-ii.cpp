class Solution {
public:
    bool valid (string &s , int l ,int r)
    {
        while(l < r)
        {
            if (s[l] == s[r])
                l++ , r--;
            else
                return 0;
        }
        return 1;
    }
    bool validPalindrome(string s) 
    {
        int st = 0 , n = s.size() - 1;
        while(st < n)
        {
            if (s[st] == s[n])
                st++ , n--;
            else {  
                bool ok = (valid(s , st + 1 , n) | (valid (s , st , n - 1)));
                if (ok)
                    return 1; 
                return 0;
            }
        }
        return 1;
    }
};