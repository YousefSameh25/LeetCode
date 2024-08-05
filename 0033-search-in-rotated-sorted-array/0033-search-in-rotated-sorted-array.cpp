class Solution {
public:
    int Search (int l, int r, vector<int>& nums, int target) 
    {
        if (l > r)
            return -1;
        int mid = (l + r) >> 1;
        if (nums[mid] == target)
            return mid;
        
        int op1 = Search(l, mid - 1, nums, target);
        int op2 = Search(mid + 1, r, nums, target);
        return max(op1, op2);
    }
    int search(vector<int>& nums, int target) {
        return Search(0, nums.size() - 1, nums, target);
    }
};