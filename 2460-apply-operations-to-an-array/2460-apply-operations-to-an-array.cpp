class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for (int i = 0 ; i + 1 < nums.size(); i++)
        {
            if (nums[i] == nums[i + 1])
                nums[i] *= 2, nums[i + 1] = 0;
        }
        vector < int > ans;
        for (auto &it: nums)
            if (it)
                ans.push_back(it);
        for (auto &it: nums)
            if (!it)
                ans.push_back(it);
        return ans;
    }
};