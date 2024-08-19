class Solution {
public:
    vector < vector < int >> dp;
    int solve (int cur, int lstCopied, int &n)
    {
        if (cur == n)
            return 0;

        int op1 = 1e9, op2 = 1e9;
        // Paste.
        if (lstCopied and cur + lstCopied <= n)
            op1 = solve(cur + lstCopied, lstCopied, n) + 1;
        // Coppy all.
        if (cur != lstCopied)
            op2 = solve(cur, cur, n) + 1;

        return min(op1, op2);
    }
    int minSteps(int n) {
        dp.resize(n + 1, vector < int > (n + 1, -1));
        return solve(1, 0, n);
    }
};