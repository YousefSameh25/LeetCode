class Solution {
public:
    bool canConstruct(string s, int k) {
        vector < int > frq(26, 0);

        for (auto &c : s) 
            frq[c - 'a']++;

        int one = 0, two = 0;
        for (auto &f : frq)
        {
            two += f / 2;
            one += f % 2;
        }

        if (one > k)
            return false;

        k -= one;

        if (k <= 0)
            return true;
        
        return two * 2 >= k;
    }
};