class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector < long long > pre(n + 1 , 0);
        
        for (int i = 1 ; i <= n ; i++)
            pre[i] = nums[i - 1] + pre[i - 1];
        
        int ans = 0;
        for (int i = 1 ; i <= n ; i++)
        {
            for (int j = i ; j <= n ;j++)
            {
                ans += (pre[j] - pre[i - 1] == k);
            }
        }
        return ans;
    }
};