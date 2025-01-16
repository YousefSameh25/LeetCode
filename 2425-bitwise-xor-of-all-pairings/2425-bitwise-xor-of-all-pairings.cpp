class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0, xor2 = 0;
        if (nums1.size() & 1)
        {
            for (auto &it : nums2)
                xor2 ^= it;
        }
        if (nums2.size() & 1)
        {
            for (auto &it : nums1)
                xor1 ^= it;
        }
        return xor1 ^ xor2;
    }
};