class Solution {
public:
    int dp[100][100][2];
    int solve (int i, int m, bool turn ,vector<int>& piles)
    {
        if (i == piles.size())
            return 0;

        int &mx = dp[i][m][turn];

        if (~mx)
            return mx;

        mx = (turn ? 0 : 1e9);
        int pre = 0;
        for (int x = 1; x <= m * 2 and i + x <= piles.size(); x++)
        {
            if (turn)
            {
                pre += piles[i + x - 1];
                mx = max(mx, pre + solve(i + x, max(m, x), 1 - turn, piles));
            }
            else
                mx = min(mx, solve(i + x, max(m, x), 1 - turn, piles));
        }
        return mx;
    } 
    int stoneGameII(vector<int>& piles) {
        memset (dp, -1, sizeof dp);
        return solve(0, 1, 1, piles);
    }
};