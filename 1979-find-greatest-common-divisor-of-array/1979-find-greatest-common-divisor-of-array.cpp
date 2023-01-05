class Solution {
public:
    int findGCD (vector<int>& nums) {
        int mn = 1e9 , mx = 0;
        for (auto  it : nums)
        {
            mx = max(mx , it);
            mn = min(mn , it);
        }
        return __gcd(mn , mx);
    }
};