class Solution {
public:
    vector < int > getOri;
    vector < long long > frq, dp;
    long long solve(int i, int& n)
    {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int next = n, newI = i + 1;
        while (newI < n and getOri[newI] - getOri[i] <= 2)
            newI++;

        if (newI != i)
            next = newI;

        long long op1 = 1LL * frq[i] * getOri[i] + solve(next, n);
        long long op2 = solve(i + 1, n);
        return dp[i] = max(op1, op2);
    }
    long long maximumTotalDamage(vector<int>& power) 
    {
        sort(power.begin(), power.end());
        int id = 0;
        getOri.resize(power.size(), 0);
        frq.resize(power.size(), 0);
        dp.resize(power.size(), -1);
        unordered_map < int , int > mp;
        for (auto &it : power)
        {
            if (mp.count(it))    
            {
                frq[mp[it]]++;
                continue;
            }
            mp[it] = id, frq[id]++ ,getOri[id++] = it;
        }
        return solve(0, id);
    }
};