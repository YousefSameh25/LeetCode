class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector < long long > pre(n , 0);
        for ( int i = 0 ; i < n ; i++)
        {
            pre[i] = 1LL * nums[i] + (i ? pre[i - 1] : 0); 
        }
        
        
        long long mx = -2e18;
        map < long long , long long > mp;
        for (int i = 0 ; i < n ; i++)
        {  
            if (mp.count(nums[i] - k) and mp.count(nums[i] + k))
            {
                mx = max({mx, pre[i] - mp[nums[i] - k] + nums[i] - k , 
                          pre[i] - mp[nums[i] + k] + nums[i] + k});
            }
            
            else  if (mp.count(nums[i] - k))
            {
                mx = max(mx, pre[i] - mp[nums[i] - k] + nums[i] - k);
            }
            
            else  if (mp.count(nums[i] + k))
            { 
                mx = max(mx, pre[i] - mp[nums[i] + k] + nums[i] + k);
            }

            if (!mp.count(nums[i]))
                mp[nums[i]] = pre[i];
            else 
                mp[nums[i]] = min(mp[nums[i]] , pre[i]);
        }
        return mx == -2e18? 0 : mx ;
    }
};