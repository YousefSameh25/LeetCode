class Solution {
public:
    int splitNum(int num) {
        vector < int > digits;
        while(num)
        {
            digits.push_back(num % 10);
            num /= 10;
        }
        sort(digits.rbegin(), digits.rend());

        int num1 = 0, num2 = 0, p1 = 1, p2 = 1;
        for (int i = 0 ; i < digits.size() ; i++)
        {
            if (i & 1)
                num1 += digits[i] * p1, p1 *= 10;
            else
                num2 += digits[i] * p2, p2 *= 10;
        }
        return num1 + num2;
    }
};