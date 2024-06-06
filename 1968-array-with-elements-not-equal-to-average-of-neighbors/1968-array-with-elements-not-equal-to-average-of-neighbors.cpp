class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int l = 0, r = nums.size() - 1;
        
        vector <int> v;
        bool t = 0;
        while (l <= r)
        {
            if (!t)
                v.push_back(nums[l++]);
            else
                v.push_back(nums[r--]);
            t ^= 1;
        }
        return v;
    }
};