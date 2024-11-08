class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) 
    {
        vector < int > ans;
        int Xor = 0;
        for (int i = 0  ; i < nums.size() ; i++)
            Xor ^= nums[i];
        
        for (int i = nums.size() - 1 ; i >= 0; i--)
        {
            int k = 0;
            for (int b = 0; b < maximumBit; b++)
            {
                if (!(Xor & (1 << b)))
                    k |= (1 << b);
            }
            ans.push_back(k);
            Xor ^= nums[i];
        }
        return ans;
    }
};