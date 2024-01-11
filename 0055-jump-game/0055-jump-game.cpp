class Solution {
public:
    
    bool canJump(vector<int>& nums) 
    {
        /*
            Idea: Greedy choice
            we have to look at last index and ask ourself how we can reach this index?
            answer: from the privous index which has value >= 1
            or      from the second privous index which has value >= 2
            or      from the third privous index which has value >= 3
            or etc.
            
            using the first valid choice will face us, we will update out target.
           
            if at the end our target = 0 the answer is true
        */
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