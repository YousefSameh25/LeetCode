class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, place = 0;
        while (i < nums.size())
        {
            if (nums[i] == val) 
            {
                i++;
                continue;
            }
            nums[place++] = nums[i++];
        }
        return place;
    }
};