class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        // There is only 3 ways
        int mn_idx = min_element(nums.begin(), nums.end()) - nums.begin();
        int mx_idx = max_element(nums.begin(), nums.end()) - nums.begin();
        
        // From left
        int op1 = max(mn_idx, mx_idx) + 1;
        
        // From right
        int op2 = nums.size() - min(mn_idx, mx_idx);
        
        // From right and left
        int op3 = (nums.size() - max(mn_idx, mx_idx)) +  (min(mn_idx, mx_idx) + 1);
        
        return min({op1, op2, op3});
    }
};