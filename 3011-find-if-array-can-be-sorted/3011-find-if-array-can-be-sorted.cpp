class Solution {
public:
    int cnt(int num) {
        int c = 0;
        while (num) {
            c += (num & 1);
            num >>= 1;
        }
        return c;
    }
    bool canSortArray(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            bool swapped = 0;
            for (int j = 0; j < nums.size() - 1 - i; j++) {
                if (nums[j] > nums[j + 1] and
                    cnt(nums[j]) ==
                        cnt(nums[j + 1])) {
                    swap(nums[j], nums[j + 1]);
                    swapped = 1;
                }
            }
            if (!swapped)
                break;
        }

        return is_sorted(nums.begin(), nums.end());
    }
};