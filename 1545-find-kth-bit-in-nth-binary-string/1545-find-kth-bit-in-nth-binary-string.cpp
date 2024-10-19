class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        n--;
        while(n-- and k > s.size())
        {
            int sz = s.size();
            s.push_back('1');
            for (int i = sz - 1 ; i >= 0 ; i--)
                s.push_back(('1' - s[i]) + '0');
        }
        return s[k - 1];
    }
};