class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        set < int > st;
        long long ans = 0;
        for (int i = 0 ; i < nums.size(); i++)
        {
            nums[i] = i - nums[i];
            st.erase(nums[i]);
            ans += 1LL * st.size();
            st.insert(nums[i]);
        }
        return ans;
    }
};