class Solution {
public:
    const int MOD = 1e9 + 7;
    int Add(int a, int b)
    {
        a %= MOD;
        b %= MOD;
        return (a + b) % MOD;
    }
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector < int > subSum;
        for (int i = 0 ; i < n; i++)
        {
            int sum = 0;
            for (int j = i ; j < n ; j++)
            {
                sum = Add(sum, nums[j]);
                subSum.push_back(sum);
            }
        }
        sort(subSum.begin(), subSum.end());

        for (int i = 1 ; i < subSum.size(); i++)
            subSum[i] = Add(subSum[i], subSum[i - 1]);
        int L = left - 1 > 0? subSum[left - 2] : 0; 
        return subSum[right - 1] - L;
    }
};