class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Mark Visit in same array
        for (int i = 0 ; i < nums.size() ; i++)
        {
            int idx = abs(nums[i]);
            if (nums[idx] < 0)
                return idx;
            nums[idx] *= -1;
        }
        return 404;
    }
};