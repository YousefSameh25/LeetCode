class Solution {
public:
    int maximumSum(vector<int>& nums) 
    {
        unordered_map < int , priority_queue < int > > mp;
        for (auto it : nums)
        {
            int tempIt = it, d = 0;
            while(it)
            {
                d += it % 10;
                it /= 10;
            }

            mp[d].push(-tempIt);
            if (mp[d].size() > 2)
                mp[d].pop();
        }
        int mx = -1;
        for (auto &st: mp)
        {
            if (st.second.size() != 2)
                continue;
            int ans = -st.second.top();
            st.second.pop();
            ans += -st.second.top();
            mx = max(mx , ans);
        }
        return mx;
    }
};