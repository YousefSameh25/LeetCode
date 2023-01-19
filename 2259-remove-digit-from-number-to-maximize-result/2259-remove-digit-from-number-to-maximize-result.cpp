class Solution {
public:
    string removeDigit(string number, char digit) 
    {
        vector < int > v;
        for (int i = 0 ;  i < number.size() ; i++)
        {
            if (number[i] == digit)
                v.push_back(i);
        }
        string mx;
        for (auto it : v)
        {
            string t;
            for (int i = 0 ; i < number.size() ; i++)
            {
                if (it == i)
                    continue;
                t.push_back(number[i]);
            }
            if (mx.size())
                 mx = max(mx , t);
            else 
                mx = t;
        }
        return mx;
    }
};