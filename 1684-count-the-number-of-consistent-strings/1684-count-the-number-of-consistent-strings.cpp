class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector < bool > vis(26, 0);
        for (auto &it : allowed)
            vis[it - 'a'] = 1;
        int cnt = 0;
        for (auto &it: words)
        {
            bool valid = 1;
            for (auto &ch : it)
            {
                if (!vis[ch - 'a'])
                {
                    valid = 0;
                    break;
                }
            }
            cnt += valid;
        }
        return cnt;
    }
};