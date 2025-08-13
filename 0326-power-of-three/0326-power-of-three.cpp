class Solution {
public:
    bool isPowerOfThree(int n) 
    {   
        int l = 0, r = 19, ans = -INT_MAX;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            long long temp = pow(3, mid);
            if (temp > n)
                r = mid - 1;
            else
            {
                ans = temp;
                l = mid + 1;
            }
        }
        return ans == n;
    }
};