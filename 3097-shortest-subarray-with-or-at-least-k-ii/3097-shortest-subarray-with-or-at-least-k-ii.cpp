class Solution {
public:
    int getValue(vector<int>& bits)
    {
        int res = 0;
        for(int i = 0 ; i < 32; i++)
        {
            if (bits[i])
                res |= (1 << i);
        }
        return res;
    }
    bool ok (vector<int>& nums, int len, int k)
    {
        vector < int > bits(32, 0);
        for (int i = 0 ; i < len; i++)
        {
            for (int j = 0; j < 32; j++)
            {
                if ((1 << j) & nums[i])
                    bits[j]++;
            }
        }
        

        int val = getValue(bits);

        if (val >= k)
            return 1;

        int lst = 0;

        for (int i = len; i < nums.size(); i++)
        {
            // remove begin
            for (int j = 0; j < 32; j++)
            {
                if ((1 << j) & nums[lst])
                    bits[j]--;
            }

            // add current
            for (int j = 0; j < 32; j++)
            {
                if ((1 << j) & nums[i])
                    bits[j]++;
            }

            val = getValue(bits);
            lst++;
            if (val >= k)
                return 1;
        }
        return 0;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) 
    {
        int l = 1, r = nums.size(), ans = -1;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if (ok(nums, mid, k))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};