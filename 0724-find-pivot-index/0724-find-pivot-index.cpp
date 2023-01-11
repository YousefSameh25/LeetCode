class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int sum = 0 , n = nums.size();
        vector < int > pre(n , 0) , suf(n , 0);
        for (int i = 0 ; i < n ; i++)
        {
            sum += nums[i];
            pre[i] = sum;
        }
        sum = 0;
         for (int i = n - 1 ; i >= 0 ; i--)
        {
            sum += nums[i];
            suf[i] = sum;
        }
        for (int i = 0 ; i < n ; i++)
        {
            if (pre[i] == suf[i])
                return i;
        }
        return -1;
    }
};