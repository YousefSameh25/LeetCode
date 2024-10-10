class Solution {
public:
    int maxWidthRamp(vector<int>& nums) 
    {
        vector < pair <int , int >> v;
        int ans = 0;
        for (int i = nums.size() - 1 ; i >= 0 ; i--)
        {
            if  (v.empty() or nums[i] > v.back().first)
            {
                v.push_back({nums[i], i});
            }
            else
            {
                auto it = lower_bound(v.begin(), v.end(), make_pair(nums[i], -10000000));
                ans = max(ans, it-> second - i);
            }
        }
        return ans;
    }
};