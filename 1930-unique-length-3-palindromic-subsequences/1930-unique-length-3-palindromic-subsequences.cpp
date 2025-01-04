class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector < int > lst(26, -1);
        for (int i = 0 ; i < s.size() ; i++)
           lst[s[i] - 'a'] = i;
        

        vector < vector < int > > pre(s.size() + 1, vector < int > (26, 0));
        for (int i = 0 ;  i < s.size(); i++)
        {
            pre[i + 1][s[i] - 'a']++;
            for (int c = 0; c < 26; c++)
                pre[i + 1][c] += pre[i][c];
        }

        vector < int > vis(26, 0);

        int ans = 0;
        for (int i = 0 ; i < s.size(); i++)
        {
            if (vis[s[i] - 'a'])
                continue;

            vis[s[i] - 'a'] = 1;

            int l = i, r = lst[s[i] - 'a'];

            if (l == r)
                continue;
            
            int dis = 0;

            for (int c = 0; c < 26; c++)
                dis += pre[r - 1 + 1][c] - pre[l + 1 + 1 - 1][c] > 0;

            cout << dis << endl;
            ans += dis;
        }
        return ans;
    }
};