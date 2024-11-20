class Solution {
public:
    bool valid (int frq[], int k)
    {
        return frq[0] >= k and frq[1] >= k and frq[2] >= k;
    }
    bool ok(string &s, int len, int k)
    {
        int frq[3] = {0 , 0 , 0};
        for (int i = 0 ; i < len ; i++)
            frq[s[i] - 'a']++;

        bool b = valid(frq, k);
        if (b)
            return b;
        
        int l = len - 1, r = s.size() - 1;
        while(l >= 0 and !b)
        {
            frq[s[l] - 'a']--;
            frq[s[r] - 'a']++;
            b = valid(frq, k);
            l--, r--;
        }
        return b;
    }
    int takeCharacters(string s, int k) {
        int l = 0, r = s.size(), ans = -1;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if (ok(s, mid, k))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};