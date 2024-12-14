class Solution {
public:
    bool valid(set < int > &st, int num)
    {
        if (st.empty())
            return 1;
        return (abs(*st.begin() - num) <= 2 and abs(*st.rbegin() - num) <= 2);
    }
    long long numberOfsubs(int len)
    {
        return (1LL * len * (len + 1) / 2);
    }
    long long continuousSubarrays(vector<int>& nums) 
    {
        nums.push_back(1e9 + 5);
        set < int > st; // to get max and min in range in O(log(n))
        map < int , int > frq; 

        int l = 0, r = 0;
        vector < pair < int , int >> ranges;
        while (r < nums.size())
        {
            if (valid(st, nums[r]))
            {
                st.insert(nums[r]);
                frq[nums[r]]++;
                r++;
            }
            else
            {
                ranges.push_back({l, r - 1});
                while(!valid(st, nums[r]) and l < r)
                {
                    frq[nums[l]]--;
                    if (frq[nums[l]] == 0)
                        st.erase(nums[l]);
                    l++;
                }
            }
        }
        long long ans = 0;
        for (int i = 0 ; i < ranges.size(); i++)
        {
            ans += numberOfsubs(ranges[i].second - ranges[i].first + 1);
            if (i and ranges[i - 1].second >= ranges[i].first)
            {
                ans -= numberOfsubs(ranges[i - 1].second - ranges[i].first + 1);
            }
        }
        return ans;
    }
};