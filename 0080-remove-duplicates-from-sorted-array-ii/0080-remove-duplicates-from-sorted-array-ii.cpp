class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int lst = nums[0] , f = 1;
        for (int i = 1 ; i < nums.size() ; i++)
        {
            if (lst != nums[i])
                lst = nums[i] , f = 1;
            else 
            {
                if (f < 2)
                {
                    f++;
                }   
                else 
                {
                    nums[i] = -1e5;
                }
            }
        }
        for (int i = 0 ; i < nums.size() ; i++)
        {
            if (nums[i] == -1e5)
            {
                cerr << "here" << " " << i << endl;
                nums.erase(i + nums.begin());
                i--;
            }
        }
        return nums.size();
    }
};