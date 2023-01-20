class Solution {
public:
    int mySqrt(int x) 
    {
        
        int s = 0 , e = x , ans = -1;
        
        while(s <= e)
        {
            int mid = (s + e) >> 1;
            if (1LL * mid * mid <= x)
            {
                s = mid + 1;
                ans = mid;
            }
            else 
            {
                e = mid - 1;
            }
        }
        return ans;
    }
};