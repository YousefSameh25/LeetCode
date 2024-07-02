class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map < int , int > mp;
        for (auto it : nums1)
            mp[it]++;
        vector <int> ans;
        for (auto it : nums2)
        {
            if (mp.count(it) and mp[it])
                ans.push_back(it), mp[it]--;
        }
        return ans;
    }
};