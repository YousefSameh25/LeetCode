class Solution {
public:
    long long minEnd(int n, int x) 
    {
        n--;
        long long end = x;
        vector < int > bits(64);
        for (int i = 0 ; i < 64; i++)
            bits[i] = (end & (1LL << i));

        vector < int > bits2(64, 0);
        for (int i = 0 ; i < 64; i++)
            bits2[i] = (n & (1LL << i));

        int i = 0 , j = 0;
        while(i < 64)
        {
            if (bits[i] == 0)
            {
                bits[i] = bits2[j];
                j++;
            }
            i++;
        }

        for (int i = 0 ; i < 64; i++)
        {
            if (bits[i])
                end |=  (1LL << i);
        }
        return end;
    }
};