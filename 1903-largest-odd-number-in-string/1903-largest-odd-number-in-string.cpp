class Solution {
public:
    string largestOddNumber(string num) 
    {
        while(num.size())
        {
            int dig = num.back() - '0';
            if (dig & 1)
                return num;
            num.pop_back();
        }
        return "";
    }
};