class Solution {
public:
    int nthUglyNumber(int n) {
        int cnt  = 0;
        for (int i = 1; ; i++)
        {
            int ii = i;
            while(ii % 2 == 0) ii /= 2;
            while(ii % 3 == 0) ii /= 3;
            while(ii % 5 == 0) ii /= 5;
            if (ii == 1)
            {
                cnt++;
                if (cnt == n)
                    return i;
            }
        }
        return 404;
    }
};