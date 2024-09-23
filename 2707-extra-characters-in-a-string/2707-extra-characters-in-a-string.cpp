class Solution {
public:
    vector < int > dp;
    int solve(int idx, string &s, vector<string>& dictionary)
    {
        if (idx == s.size())
            return 0;
        
        if (dp[idx] != -1)
            return dp[idx];

        int op1 = solve(idx + 1, s, dictionary) + 1;

        int op2 = INT_MAX;
        for (auto &word : dictionary)
        {
            if (s.find(word, idx) == idx)
                op2 = min(op2, solve(idx + word.size(), s, dictionary));
        }
        return dp[idx] = min(op1, op2);
    } 
    int minExtraChar(string s, vector<string>& dictionary) {
        dp.resize(s.size() + 1, -1);
        return solve(0, s, dictionary);
    }
};