class Solution {
public:
    int longestPalindrome(string s) {
        vector <int> v(100,0);
        for (char c : s) v[c-'A']++;
        int ans = 0 , o = 0;
        for (int i = 0 ; i < v.size() ; i++)
        {
            if (v[i] & 1)
                o = 1;
            ans += (v[i] - (v[i] & 1));
        }
        ans += o;
        return ans;
    }
};