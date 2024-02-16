class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        int n = nums.size();
        vector <int> pre(n , 0), suf(n + 1 , 0);
        for (int i = 0 ; i < n ; i++)
        {
            pre[i] = nums[i];
            if (i)
                pre[i] += pre[i - 1];
        }
        int z = 0;
        for (int i = n - 1 ; i >= 0 ; i--)
        {
            z += !nums[i];
            if (nums[i])
                z = 0;
            suf[i] = z;
        }
        
        int ans = 0;
        for (int i = 0 ; i < n; i++)
        {
            int l = 1, r = n - i , best = -1;
            while(l <= r)
            {
                int len = (l + r) >> 1;
                long long sumR = pre[i + len - 1] - ((i - 1 >= 0) ? pre[i - 1] : 0);
                if (sumR >= goal)
                {
                    if (sumR == goal)
                        best = i + len - 1;
                    r = len - 1;
                }
                else
                {
                    l = len + 1;
                }
            }
            if (best != -1)
                ans += suf[best + 1] + 1;
        }
        return ans;
    }
};