class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        /*
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
        */
        
        // Another solution
        
        if (nums.size() == 1)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int l = 0, r = 1, ans = 0;
        
        while(l < nums.size() and r < nums.size())
        {
            if (nums[r] > nums[l])
                ans++ , r++, l++;
            else
                r++;
        }
        return ans;
    }
};