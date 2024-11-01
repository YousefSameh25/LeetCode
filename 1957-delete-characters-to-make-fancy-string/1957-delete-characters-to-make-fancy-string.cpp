class Solution {
public:
    bool checkLastTwo(string &s,  char a)
    {
        if (s.size() < 2)
            return 1;
        if (s[s.size() - 1] == a and s[s.size() - 2] == a)
            return 0;
        return 1;
    }
    string makeFancyString(string s) {
        string ans;
        for (int i = 0 ;  i < s.size() ; i++)
        {
            if (checkLastTwo(ans, s[i]))
                ans.push_back(s[i]);
        }
        return ans;
    }
};