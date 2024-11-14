class Solution {
public:
    int ok (int n, int mx , vector<int>& quantities)
    {
        for (int i = 0; i < quantities.size(); i++)
        {
            int need = (quantities[i] + mx - 1) / mx;
            if (need > n)
                return 0;
            n -= need;
        }
        return 1;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = 1e5, ans = 0;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(ok(n, mid, quantities))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};