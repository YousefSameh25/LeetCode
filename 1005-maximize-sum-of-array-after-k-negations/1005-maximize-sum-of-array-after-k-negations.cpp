class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k)
    {
      
        sort(nums.begin() , nums.end());
        for (int i = 0 ; i < nums.size() && k && nums[i] < 0 ; i++ , k--)
            nums[i] *= -1;
        
        int mn= 1e9 , sum = 0;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            sum += nums[i];
            mn = min(mn , nums[i]);
        }
        return sum - (k & 1) * mn * 2;
        
    }
};