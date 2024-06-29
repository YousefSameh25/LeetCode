class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        multiset < int > mst;
        for (auto it : nums)
            mst.insert(it);
        
        int ans = 0;
        for (auto it : nums)
        {
            auto iter = mst.upper_bound(it);
            if (iter == mst.end())
                continue;
            ans++;
            mst.erase(iter);
        }
        return ans;
    }
};