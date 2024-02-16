class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int n = nums.size();
        for (int i = 0; i < n ; i++)
        {
            nums[i] %= k, nums[i] += k, nums[i] %= k;
            if (i)
            {
                nums[i] += nums[i - 1];
                nums[i] %= k;
            }
        }
        
        int ans = 0; 
        map < int , int > mp;
        mp[0] = 1;
        for ( int i = 0 ; i < n ; i++)
        {
            ans += mp[nums[i]];
            mp[nums[i]]++;
        }
        
        return ans;
    }
};