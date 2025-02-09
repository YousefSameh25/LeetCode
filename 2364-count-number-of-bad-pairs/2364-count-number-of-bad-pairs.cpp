class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        multiset < int > st;
        map <int , int > mp;
        long long ans = 0;
        for (int i = 0 ; i < nums.size(); i++)
        {
            nums[i] = i - nums[i];
            ans += 1LL * (st.size() - mp[nums[i]]);
            st.insert(nums[i]);
            mp[nums[i]]++;
        }
        return ans;
    }
};