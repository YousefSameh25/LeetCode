class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i < n ; i++)
        {
            int num = nums[i];
            for(int j = i; j < n; j++)
            {
                num = (num * nums[j]) / __gcd(num , nums[j]);
                if(num==k) 
                    cnt++;
                
                if(num > k) 
                    break;
            }
        }
        return cnt;
    }
};