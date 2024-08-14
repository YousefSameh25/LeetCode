class Solution {
public: 
    int smallestDistancePair(vector<int>& nums, int k) 
    {
        vector < int > diff(1000000 + 1, 0);
        int mxDiff = -1;
        for (int i = 0; i < nums.size(); i++)
           for (int j = i + 1 ; j < nums.size() ; j++)
            {
                diff[abs(nums[i] - nums[j])]++;
                mxDiff = max(mxDiff, abs(nums[i] - nums[j]));
            }

        int cnt = 0;
        for (int i = 0 ; i <= mxDiff; i++)
        {
            cnt += diff[i];
            if (cnt >= k)
                return i;
        }
           
        return 404;   
    }
};
static const auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    return 0;
} ();