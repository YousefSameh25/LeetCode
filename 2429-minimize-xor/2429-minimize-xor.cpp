class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bits = __builtin_popcount(num2);
        int x = 0;
        for (int i = 31; i >= 0 and bits; i--)
        {
            if ((1 << i) & num1)
            {
                x |= (1 << i);
                bits--;
            }
        }
        for (int i = 0; i < 32 and bits; i++)
        {
            if (((1 << i) & x) == 0)
            {
                x |= (1 << i);
                bits--;
            }
        }
        return x;
    }
};