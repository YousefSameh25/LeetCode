class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector <int> newarr(nums.size());
        for (int i = 0 ; i < nums.size() ; i++)
        {
            int newi = (i + k) % nums.size();
            newarr[newi] = nums[i];
        }
        nums = newarr;
    }
};