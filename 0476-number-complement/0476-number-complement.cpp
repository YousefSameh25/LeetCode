class Solution {
public:
    int findComplement(int num) {
        string s;
        while(num)
        {
            s.push_back((num % 2) + '0');
            num /= 2;
        }
        reverse(s.begin(), s.end());
        for (auto &it : s)
            it = ('1' - it) + '0';

        int num2 = 0, p = 0;
        for (int i = s.size() - 1; i >= 0 ; i--)
        {
            num2 += (s[i] - '0') * (1 << p);
            p++;
        }

        return num2;
    }
};