class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int diff = 1e9, ans = -1;
        for (int i = 0 ; i + 2 < nums.size(); i++)
        {
            for (int j = i + 1 ; j + 1 < nums.size(); j++)
            {
                int rem = target - (nums[i] + nums[j]);
                int up = upper_bound(nums.begin() + j + 1, nums.end(), rem) - nums.begin();
                int down = up - 1;
                if (up > j and up < nums.size())
                {
                    int sum = nums[i] + nums[j] + nums[up];
                    if (abs(sum - target) < diff)
                    {
                        ans = sum;
                        diff = abs(sum - target);
                    }
                }
                if (down > j and down < nums.size())
                {
                    int sum = nums[i] + nums[j] + nums[down];
                    if (abs(sum - target) < diff)
                    {
                        ans = sum;
                        diff = abs(sum - target);
                    }
                }
            }
        }
        return ans;
    }
};