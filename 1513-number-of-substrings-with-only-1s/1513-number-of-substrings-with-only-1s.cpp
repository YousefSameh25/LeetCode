class Solution {
public:
    int MOD = 1e9 + 7;
    int numSub(string s) {
        int ones = 0, ans = 0;
        for (auto &it : s)
        {
            if (it == '1')
            {
                ans = ((ans + 1) % MOD);
                ans = ((ans % MOD) + (ones % MOD)) % MOD;
            }
            it == '1'? ones++: ones = 0;
        }
        return ans;
    }
};