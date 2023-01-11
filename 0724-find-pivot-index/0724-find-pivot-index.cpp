class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int sump = 0 , sums = 0 , n = nums.size();
        vector < int > pre(n , 0) , suf(n , 0);
        for (int i = 0 ; i < n ; i++)
        {
            sump += nums[i];
            sums += nums[n - i - 1];
            pre[i] = sump;
            suf[n - i - 1] = sums;
        }
        for (int i = 0 ; i < n ; i++)
        {
            if (pre[i] == suf[i])
                return i;
        }
        return -1;
    }
};