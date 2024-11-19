class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, sum = 0;
        vector < int > frq(100000 + 10, 0);
        set < int > st;
        for (int i = 0 ; i < k ; i++)
            frq[nums[i]]++, st.insert(nums[i]), sum += 1LL * nums[i];

        if (st.size() == k)
            ans = sum;

        int s = 0, e = k;
        while(e < nums.size())
        {
            frq[nums[s]]--, frq[nums[e]]++;
            sum -= nums[s], sum += 1LL * nums[e];
            st.insert(nums[e]);
            if (!frq[nums[s]])
                st.erase(nums[s]);
            if (st.size() == k)
                ans = max(ans, sum);
            s++, e++;
        }
        return ans;
    }
};