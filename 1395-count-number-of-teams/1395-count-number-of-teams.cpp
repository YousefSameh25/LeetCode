class Solution {
public:
    int dp[1000][1000][3];
    int solve(int i, int lst, int len, vector<int>& rating) {
        if (i == rating.size())
            return 0;

        if (lst != -1 and dp[i][lst][len] != -1)
            return dp[i][lst][len];

        int ans = 0;
        if (lst == -1 or rating[i] > rating[lst]) {
            if (len <= 1)
                ans = solve(i + 1, i, len + 1, rating);
            else if (len == 2) 
                ans++;
        }

        ans += solve(i + 1, lst, len, rating);

        if (lst != -1)
            dp[i][lst][len] = ans;
        return ans;
    }

    int numTeams(vector<int>& rating) {
        memset(dp, -1, sizeof dp);
        int ans = solve(0, -1, 0, rating);
        reverse(rating.begin(), rating.end());
        memset(dp, -1, sizeof dp);
        ans += solve(0, -1, 0, rating);
        return ans;
    }
};