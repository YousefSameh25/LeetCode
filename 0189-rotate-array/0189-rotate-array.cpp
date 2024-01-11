class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // We can't store at the original array as we will lose the value in the new index.
        vector <int> newarr(nums.size());
        for (int i = 0 ; i < nums.size() ; i++)
        {
            int newi = (i + k) % nums.size();
            newarr[newi] = nums[i];
        }
        nums = newarr;
    }
};