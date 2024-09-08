class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target > nums.back())
            return nums.size();
        int l = 0, r = nums.size() - 1, ans = -1;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target)
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        return ans;
    }
};