class Solution {
public:
    int dp[1001][1001]; 
    int solve (int i, int mxHeight, int shelfWidth, int &originalShelfWidth, vector<vector<int>>& books)
    {
        if (i == books.size())
            return 0;
        
        int &ans = dp[i][shelfWidth];
        if (~ans)
            return ans;

        ans = 1e9;
        if (books[i][0] <= shelfWidth)
        {
            ans = solve(i + 1, max(mxHeight, books[i][1]), shelfWidth - books[i][0], 
                originalShelfWidth, books);
            if (mxHeight < books[i][1])
                ans -= mxHeight, ans += books[i][1];
        }
        ans = min(ans, 
            solve(i + 1, books[i][1], originalShelfWidth - books[i][0], originalShelfWidth, books) + books[i][1]);
        return ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset (dp , -1, sizeof dp);
        return solve(0, 0, shelfWidth, shelfWidth, books);
    }
};