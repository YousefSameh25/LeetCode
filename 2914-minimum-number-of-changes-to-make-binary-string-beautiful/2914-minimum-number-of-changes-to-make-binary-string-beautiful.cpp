class Solution {
public:
    int minChanges(string s) {
        s += "#";
        int cnt = 0;
        char c = s[0];
        vector < int > v;
        for (int i = 0; i < s.size() ; i++)
        {
            if (c == s[i])
            {
                cnt++;
            } 
            else
            {
                v.push_back(cnt);
                cnt = 1;
                c = s[i];
            }
        }

        int ans = 0;
        for (int i = 0 ; i < v.size() - 1; i++)
        {
            if (!(v[i] & 1))
                continue;
            if (v[i] & 1)
            {
                ans++;
                v[i]++, v[i + 1]--;
            }
        }
        return ans;
    }
};