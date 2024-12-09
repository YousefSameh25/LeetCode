class Solution {
public:
    bool isbad(int i, int j)
    {
        return ((i + j) % 2 == 0);
    }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector < int > bad;
        for (int i = 0 ;  i < nums.size() - 1 ; i++)
        {
            if (isbad(nums[i], nums[i + 1]))
                bad.push_back(i + 1);
        }
        vector < bool > ans;
        for (int i = 0  ; i < queries.size();  i++)
        {
            int l = queries[i][0], r = queries[i][1];
            auto it = lower_bound(bad.begin(), bad.end(), l + 1);
            if (it == bad.end())
                ans.push_back(true);
            else
                ans.push_back(!(*it >= l and *it <= r));
        }
        return ans;
    }
};