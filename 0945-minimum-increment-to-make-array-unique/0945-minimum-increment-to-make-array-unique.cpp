class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) 
    {
        sort (nums.begin() , nums.end());
        int ret = 0;
        for (int i = 1 ; i < nums.size() ; i++) 
        {
            if (nums[i] <= nums[i - 1])
            {
                ret += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }
        return ret;
    }
     // 1 1 2 2 3 7
     // 1 2 3 4 5 7
};