class Solution {
public:
    string removeDigit(string number, char digit) 
    {
        int idx = 0;
        for (int i = 0 ; i < number.size() ; i++)
        {
            if (number[i] == digit)
            {
                idx = i;
                if (i + 1 < number.size() and number[i] < number[i + 1])
                    break;
            }
        }
        number.erase(idx , 1);
        return number;
    }
};