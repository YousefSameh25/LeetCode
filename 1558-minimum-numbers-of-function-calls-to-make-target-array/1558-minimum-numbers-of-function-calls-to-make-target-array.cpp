class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        while(1)
        {
            int cnt = 0, zeros = 0;
            for (int i = 0 ; i < nums.size(); i++)
                cnt += nums[i] % 2, zeros += !nums[i];

            if (zeros == nums.size())
                break;

            if (cnt)
            {
                for (int i = 0 ; i < nums.size(); i++)
                {
                    if (nums[i] & 1)
                        nums[i]--, ans++;
                }
            }
            else
            {
                for (int i = 0 ; i < nums.size(); i++)
                {
                    if (nums[i])
                        nums[i] /= 2;
                }
                ans++;
            }
        }
    
        return ans;
    }
};