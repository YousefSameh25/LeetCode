class Solution {
public:
    int minimizeXor(int num1, int num2) {
        
        vector < int > b1(32, 0);
        int bits = 0;
        for (int i = 0 ; i < 32; i++)
        {
            b1[i] = ((num1 >> i) & 1);
            bits += ((num2 >> i) & 1);
        }
        
        vector < int > x(32, 0);
        for (int i = 31; i >= 0 and bits ; i--)
        {
            if (b1[i])
                x[i] = 1, bits--;
        }
        
        // Set the remaining bits
        
        for (int i = 0 ; i < 32 and bits; i++)
        {
            if (!x[i])
                x[i] = 1, bits--;
        }
        
        int xx = 0;
        for (int i = 0 ; i < 32; i++)
            if(x[i])
                xx += (1 << i);
        
        return xx;
    }
};