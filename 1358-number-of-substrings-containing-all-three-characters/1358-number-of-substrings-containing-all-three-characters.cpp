class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int n = s.size();
        int frq[n][3];
        
        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < 3 ; j++)
                frq[i][j] = 0;
        
        for (int i = 0 ; i < n ; i++)
        {
            frq[i][s[i] - 'a']++;
            if (i)
            {
                frq[i][0] += frq[i-1][0];
                frq[i][1] += frq[i-1][1];
                frq[i][2] += frq[i-1][2];
            }
        }
        int ret = 0;
        for (int i = 0 ; i < n ; i++)
        {
            int l = 1 , r = n - i , ans = -1;
            while(l <= r)
            {
                int len = (l + r) >> 1;
                int RA = frq[i + len - 1][0] - ((i)? frq[i - 1][0] : 0);
                int RB = frq[i + len - 1][1] - ((i)? frq[i - 1][1] : 0);
                int RC = frq[i + len - 1][2] - ((i)? frq[i - 1][2] : 0);
                if (RA and RB and RC) {
                    ans = i + len - 1;
                    r = len - 1;
                } else {
                    l = len + 1;
                }
            }
            
            if (ans == -1)
                break;
            ret += n - ans;
        }
        
        return ret;
    }
};