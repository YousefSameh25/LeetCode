class Solution 
{
public:
 vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (i and nums[i] == nums[i - 1])
            continue;
        int a = nums[i], l = i + 1, r = nums.size() - 1;
        while (l < r) {
            int have = a + nums[l] + nums[r];
            if (have == 0) {
                ans.push_back({a, nums[l++], nums[r]});
                while (l < r and nums[l] == nums[l - 1])
                    l++;
            } else if (have > 0)
                r--;
            else
                l++;
        }
    }
    return ans;
}
};