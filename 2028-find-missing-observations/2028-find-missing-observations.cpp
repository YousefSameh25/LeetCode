class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        // Find the empty case:
        int sum = 0;
        for (auto &it : rolls)
            sum += it;
        int mis = mean * (rolls.size() + n) - sum;
        if (mis <= 0)
            return {};
        if (mis < n)
            return {};

        vector < int > ans(n, 1);
        mis -= n;
        for (int i = 0 ; i < n; i++)
        {
            ans[i] += min(mis, 5);
            mis -= ans[i] - 1;
        }
        if (mis)
            return {};
        return ans;
    }
};