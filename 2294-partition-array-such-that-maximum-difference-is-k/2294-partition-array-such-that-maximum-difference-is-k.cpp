class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        // 1 2 3 5 6
        int n = nums.size(), i = 0 , ans = 0;
        while(i < n)
        {
            int cur = nums[i];
            while(i < n and nums[i] - cur <= k) i++;
            ans++;
        }
        return ans;
    }
};