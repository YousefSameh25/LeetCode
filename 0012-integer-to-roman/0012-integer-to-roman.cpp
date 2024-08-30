class Solution {
public:
    int firstDigit(int num)
    {
        string temp = to_string(num);
        return temp[0] - '0';
    }

    string intToRoman(int num) {
        char Roman[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int Value[7] = {1, 5, 10, 50, 100, 500, 1000};
        string strRoman;
        while(num >= 1000)
        {
            strRoman.push_back('M');;
            num -= 1000;
        }

        int p = 1;
        while(num)
        {
            int cur;
            if (num >= 100)
                cur = num % 1000 - num % 100;
            else if (num >= 10)
                cur = num % 100 - num % 10;
            else
                cur = num % 10;

            num -= cur;
            
            while(cur)
            {
                if (firstDigit(cur) != 4 and firstDigit(cur) != 9)
                {
                    for (int j = 6; j >= 0; j--)
                    {
                        if (Value[j] <= cur)
                        {
                            strRoman.push_back(Roman[j]);
                            cur -= Value[j];
                            break;
                        }
                    }
                }
                else 
                {
                    if (firstDigit(cur) == 4 and cur == 4)
                    {
                        strRoman += "IV";
                    }
                    else if (firstDigit(cur) == 4 and cur == 40)
                    {
                        strRoman += "XL";
                    }
                    else if (firstDigit(cur) == 4 and cur == 400)
                    {
                        strRoman += "CD";
                    }
                    else if (firstDigit(cur) == 9 and cur == 9)
                    {
                        strRoman += "IX";
                    }
                    else if (firstDigit(cur) == 9 and cur == 90)
                    {
                        strRoman += "XC";
                    }
                    else if (firstDigit(cur) == 9 and cur == 900)
                    {
                        strRoman += "CM";
                    } 
                    cur = 0;
                }
            }
        }
        return strRoman;
    }
};