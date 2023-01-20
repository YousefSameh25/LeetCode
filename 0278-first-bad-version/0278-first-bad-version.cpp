// The API isBadVersion is defined for you.
// bool isBadVersion(mid)(

class Solution {
public:
    int firstBadVersion(int n) 
    {
        int s = 1 , e = n , ans = -1;
        while(s <= e)
        {
            int mid = (1LL * s + e) >> 1;
            if (isBadVersion(mid))
            {
                  e = mid - 1;
                  ans = mid;
            }
            else 
            {
                s = mid + 1;
            }
        }
        return ans;
    }
};