class Solution {
public:
    vector < int > dp;
    int next (int i, vector<int>& days, int c)
    {
        int end = days[i] + c;
        while(i < days.size() and end > days[i])
            i++;
        return i;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs, int i = 0) 
    {
        if (i == days.size())
            return 0;
            
        if (i == 0)
            dp.resize(366, -1);

        int &ans = dp[days[i]];

        if (~ans)
            return ans;

        int op1 = mincostTickets(days, costs, next(i, days, 1)) + costs[0];
        int op2 = mincostTickets(days, costs, next(i, days, 7)) + costs[1];
        int op3 = mincostTickets(days, costs, next(i, days, 30)) + costs[2];
        return ans = min({op1, op2, op3});
    }
};