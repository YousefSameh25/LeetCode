class Solution {
public:
    bool isPowerOfThree(int n) 
    {   
        int l = 0, r = 20;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            long long ans = pow(3, mid);
            if (ans == n)
                return true;
            if (ans > n)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};