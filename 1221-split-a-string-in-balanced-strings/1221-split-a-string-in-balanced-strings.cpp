class Solution {
public:
    int balancedStringSplit(string s) {
        int mx = 0 , cnt = 0;
        for (char c : s)
        {
            (c == 'L') ? cnt++ : cnt--;
            mx += (cnt == 0);
        }
        return mx;
    }
};