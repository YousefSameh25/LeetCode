class Solution {
public:
    int myAtoi(string s) 
    {
        long long a = 0;
        try
        {
            a = stol(s);
        }
        catch (...)
        {
            a = 0;
        }
        if (a > INT_MAX)
            return INT_MAX;
        if (a < INT_MIN)
            return INT_MIN;

        return a;
    }
};