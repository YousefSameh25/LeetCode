class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n = nums.size();
        vector <long long> pre(n , 0);
        
        for (int i = 0 ; i < n ; i++)
        {
            pre[i] = nums[i];
            if (i)
                pre[i] += 1LL * pre[i - 1];
        }
        
        int ans = 1e9;
        for (int i = 0 ; i < n; i++)
        {
            int l = 1, r = n - i , best = 1e9;
            while(l <= r)
            {
                int len = (l + r) >> 1;
                long long sumR = pre[i + len - 1] - ((i - 1 >= 0) ? pre[i - 1] : 0);
                
                if (sumR >= target)
                {
                    best = len;
                    r = len - 1;
                }
                else 
                {
                    l = len + 1;
                }
            }
            ans = min(ans , best);
           
        }
        
        return (ans == 1e9 ? 0 : ans);
    }
};