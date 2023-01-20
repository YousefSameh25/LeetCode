class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pos = lower_bound (nums.begin() , nums.end() , target) - nums.begin();
        return (pos < nums.size() and nums[pos] == target) ? pos : -1;
    }
};