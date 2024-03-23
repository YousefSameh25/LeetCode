class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        
        int k = k1 + k2;
        map <int, int> mp;
        
        int levels = -1;
        for (int i = 0 ; i < nums1.size() ; i++)
        {
            int diff = abs(nums1[i] - nums2[i]);
            mp[diff]++;
            levels = max(levels, diff);
        }
        
        for (int i = levels ; i >= 0 ; i--)
        {
            int minus = min(k , mp[i]);
            mp[i] -= minus;
            
            mp[i - 1] += minus;
            
            k -= minus;
        }
        
        long long ans = 0;
        for (int i = 1 ; i <= levels; i++)
            ans += 1LL * i * i * mp[i];
        
        return ans;
    }
};