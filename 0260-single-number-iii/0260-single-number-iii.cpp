class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int pairXor = nums[0];
        
        for (int i = 1 ; i < nums.size() ; i++)
            pairXor ^= nums[i];
        
        // 6 , [1,2,1,3,2,5]
        

        
        int firstBit;
        
        for (int i = 0; i < 32 ; i++)
        {
            if ((pairXor & (1 << i)) == (1 << i))
            {
                firstBit = i;
                break;
            }
        }
        
        
        vector <int> ans(2, 0);
        for (int i = 0 ; i < nums.size() ; i++)
        {
            if ((nums[i] & (1 << firstBit)) == 0)
                ans[0] ^= nums[i];
            else 
                ans[1] ^= nums[i];
        }
        
        return ans;
    }
};