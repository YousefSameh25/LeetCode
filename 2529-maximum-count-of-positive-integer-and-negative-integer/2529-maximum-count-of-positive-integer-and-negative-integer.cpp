class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos1 = lower_bound(nums.begin() ,nums.end() , 0) - nums.begin();
        int pos2 = upper_bound(nums.begin() ,nums.end() , 0) - nums.begin();
        return max(pos1 , (int) nums.size() - pos2);
    }
};