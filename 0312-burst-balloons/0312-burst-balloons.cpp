class Solution 
{
    public:
    int memo[310][310];
    int maxCoins(vector <int> nums) 
    {
        int n = nums.size();
        vector <int> arr(n + 2 , 1);
        
        for(int i = 1 ; i <= n ; i++) 
            arr[i] = nums[i-1];
        
        memset (memo , -1 , sizeof memo);
        
        return burst(arr, 0, n + 1);
    }
   int burst(vector <int>& nums, int left, int right) 
   {

       // Internal range is empty.
        if (left + 1 == right) 
            return 0;

        if (~memo[left][right]) 
            return memo[left][right];

        int ans = 0;

        for (int i = left + 1; i < right; ++i){
            ans = max(ans, nums[left] * nums[i] * nums[right] 
            + burst(nums, left, i) + burst(nums, i, right));
        }
        memo[left][right] = ans;

        return ans;
    }
    
};