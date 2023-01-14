class Solution {
public:
    bool lemonadeChange(vector<int>& bills)
    {
        int c5 = 0, c10 = 0, c20 = 0;
        for (auto it : bills)
        {
            if (it == 5)
                c5++;
            else if (it == 10)
            {
                if (c5 >= 1)
                    c5--;
                else
                    return false;
                c10++;
            } 
            else
            {
                 if (c5 >= 1 and c10 >= 1)
                    c5-- , c10--;
                 else if (c5 >= 3)
                     c5 -=3;
                else
                    return false;
                c20++;
            } 
        }
        return true;
    }
};