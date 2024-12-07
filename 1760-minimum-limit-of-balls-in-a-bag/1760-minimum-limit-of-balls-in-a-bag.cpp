class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        long long bags = maxOperations + nums.size();
        long long sum = 0;
        for (auto it : nums)
        {
            sum += 1LL * it;
        }
       return sum / bags + sum % bags;
    }
};