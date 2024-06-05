class Solution {
public:
    bool IsVowel (char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o'
            || c == 'u';
    }
    
    int beautifulSubstrings(string s, int k) 
    {
        int ans = 0;
        for (int i = 0 ; i < s.size(); i++)
        {
            int C = 0, V = 0;
            for (int j = i ; j < s.size(); j++)
            {
                if (IsVowel(s[j]))
                    V++;
                else 
                    C++;
                if (V == C and (V * C) % k == 0)
                    ans++;
            }
        }
        return ans;
    }
};