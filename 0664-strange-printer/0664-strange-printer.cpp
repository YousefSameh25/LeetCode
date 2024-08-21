class Solution {
public:
    int dp[100][100];
    int solve(int start, int end, string &s)
    {
        if (start > end)
            return 0;

        if (dp[start][end] != -1)
            return dp[start][end];

        // Print the first char with cost 1 and solve the remaining string.
        int op1 = 1 + solve(start + 1, end, s);
        
        // Try to find a sub that has a start = end and save the end char.
        for (int i = start + 1; i <= end; i++)
        {
            if (s[start] != s[i])
                continue;
            op1 = min(op1, solve(start, i - 1, s) + solve(i + 1, end, s));
        }
        return dp[start][end] = op1;
    }
    int strangePrinter(string s) 
    {
        string s2;
        for (int i = 0 ; i < s.size(); i++)
        {
            if (s2.empty() or s2.back() != s[i])
                s2.push_back(s[i]);
        }
        s = s2;
        memset (dp , -1, sizeof dp);
        return solve(0, s.size() - 1, s);
    }
};