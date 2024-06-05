class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map <int , int> part1, part2;
        
        for (auto &it1 : nums1)
            for (auto &it2 : nums2)
                part1[it1 + it2]++;
        
        for (auto &it3 : nums3)
            for (auto &it4 : nums4)
                part2[it3 + it4]++;
    
        
        int ans = 0;
        for (auto it : part1)
        {
            if (!part2.count(-it.first))
                continue;
            ans += it.second * part2[-it.first];
        }
        
        return ans;
    }
};