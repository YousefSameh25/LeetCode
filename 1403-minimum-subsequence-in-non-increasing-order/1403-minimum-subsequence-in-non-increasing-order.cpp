class Solution {
public:
    vector<int> minSubsequence(vector<int> & nums) 
    {
        sort(nums.begin() , nums.end());
        reverse(nums.begin() , nums.end());
        int sum = accumulate(nums.begin() , nums.end() , 0) , cur = 0;
        vector < int > ans;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            cur += nums[i];
            sum -= nums[i];
            ans.push_back(nums[i]);
            if (cur > sum)
                break;
        }
        return ans;
    }
};