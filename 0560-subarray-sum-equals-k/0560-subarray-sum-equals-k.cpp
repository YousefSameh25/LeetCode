class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector < int > pre(n + 1 , 0);
        
        for (int i = 1 ; i <= n ; i++)
            pre[i] = nums[i - 1] + pre[i - 1];
        
        int ans = 0;
        unordered_map < int , int > mp;
        
        // Let's try every index to be the end of the subarray
        // and let's find out how many starting points are suitable?
        for (int i = 0 ; i <= n ; i++)
        {
            ans += mp[pre[i] - k];
            mp[pre[i]]++;
        }
        return ans;
    }
};