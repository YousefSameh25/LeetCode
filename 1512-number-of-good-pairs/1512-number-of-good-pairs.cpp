class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map <int , int> mp;
        int ret = 0;
        for (auto it : nums)
        {
            ret += mp[it];
            mp[it]++;
        }
        return ret;
    }
};