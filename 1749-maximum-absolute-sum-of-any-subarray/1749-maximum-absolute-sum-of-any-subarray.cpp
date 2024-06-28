class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) 
    {
        int sum = 0;
        int mx = -1e9;
        for (int i = 0 ; i < nums.size(); i++)
        {
            int temp = max(nums[i] , sum + nums[i]);
            sum = temp;
            mx = max(mx , sum);
        }
        
        int mn = 1e9;
        sum = 0;
        for (int i = 0 ; i < nums.size(); i++)
        {
            int temp = min(nums[i] , sum + nums[i]);
            sum = temp;
            mn = min(mn , sum);
        }
        
        return max(mx , abs(mn));
        
    }
};