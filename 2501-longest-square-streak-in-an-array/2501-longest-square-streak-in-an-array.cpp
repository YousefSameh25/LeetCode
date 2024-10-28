class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map < int, bool > mp;
        for (auto &num: nums)
            mp[num] = 1;

        int ans = 0;
        for (auto &num: nums)
        {
            long long temp = num;
            int cnt = 0;
            while(temp <= INT_MAX and mp.count(temp))
                temp *= temp, cnt++;
            ans = max(ans, cnt);
        }
        if (ans == 1)
            ans = -1;
        return ans;
    }
};