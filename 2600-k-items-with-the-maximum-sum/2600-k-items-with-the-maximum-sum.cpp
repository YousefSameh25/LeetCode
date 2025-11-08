class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int cnt[3] = {numOnes, numZeros, numNegOnes};
        int val[3] = {1, 0, -1};
        int ans = 0;
        for (int i = 0 ; k && i < 3 ; i++)
        {
            int can = min(k, cnt[i]);
            ans += can * val[i];
            k -= can;
        }
        return ans;
    }
};