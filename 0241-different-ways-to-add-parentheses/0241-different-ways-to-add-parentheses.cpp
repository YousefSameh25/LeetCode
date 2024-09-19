class Solution {
public:
    int apply(char op, int a, int b)
    {
        if (op == '+')
            return a + b;
        else if (op == '-')
            return a - b;
        return a * b;
    }
    vector < int > memo[20][20];
    vector < int > solve (int l, int r, string & ex)
    {
        if (l == r)
            return {ex[l] - '0'};
        if (r - l == 1) 
            return {(ex[l] - '0') * 10 + (ex[r] - '0')};

        vector < int > &ans = memo[l][r];

        if (ans.size())
            return ans;

        for (int i = l + 1; i < r; i++)
        {
            if (ex[i] != '+' and ex[i] != '-' and ex[i] != '*')
                continue;
            vector < int > L = solve(l ,i - 1, ex);
            vector < int > R = solve(i + 1, r, ex);
            for (auto it : L)
                for (auto it2 : R)
                    ans.push_back(apply(ex[i], it, it2));
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(0, expression.size() - 1, expression);
    }
};