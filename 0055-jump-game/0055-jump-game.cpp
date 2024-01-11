class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int curidx = nums.size() - 1;
        int pre = curidx - 1;
        int len = 1;
        while(pre >= 0)
        {
            if (nums[pre] >= len)
            {
                curidx = pre;
                pre  = curidx - 1;
                len = 1;
            }
            else 
            {
                len++;
                pre--;
            }
        }
        return !curidx;
    }
};