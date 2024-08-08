class Solution {
public:
    int cal (char a, char b)
    {
        return abs(a - b);
    }
    int equalSubstring(string s, string t, int maxCost) {
        int l = 0, r = 0;
        int mx = 0;
        int totalCost = 0;

        while (r < t.size())
        {
            if (totalCost + cal(s[r], t[r]) <= maxCost)
            {
                totalCost += cal(s[r], t[r]);
                mx = max(r - (l - 1), mx);
                r++;
            }
            else
            {
                if (l < r)
                {
                    totalCost -= cal(s[l], t[l]);
                    l++;
                }
                if (l >= r)
                    l++, r++;
            }
        }
        return mx;
    }
};