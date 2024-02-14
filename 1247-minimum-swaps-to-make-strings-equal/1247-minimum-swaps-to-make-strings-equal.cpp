class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if (s1 == s2)
            return 0;
        int s1x = count(s1.begin() , s1.end(), 'x');
        int s1y = count(s1.begin() , s1.end(), 'y');
        int s2x = count(s2.begin() , s2.end(), 'x');
        int s2y = count(s2.begin() , s2.end(), 'y');
        if ((s1x + s2x) & 1 or (s1y + s2y) & 1)
            return -1;
        
        int res = 0, xy = 0 , yx = 0;
        for (int i = 0 ; i < s1.size() ; i++)
        {
            if (s1[i] == s2[i])
                continue;
            if (s1[i] == 'x')
                xy++;
            else
                yx++;
            res++;
        }
        
        return res - xy / 2 - yx / 2;
    }
};