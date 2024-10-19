class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        n--;
        while(n--)
        {
            string s2 = s;
            reverse(s2.begin(), s2.end());
            s.push_back('1');
            for (auto it : s2)
                s.push_back(('1' - it) + '0');
        }
        return s[k - 1];
    }
};