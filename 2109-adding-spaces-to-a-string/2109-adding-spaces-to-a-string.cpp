class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        int j = 0;
        for (int i = 0 ; i < s.size() ; i++)
        {
            if (j < spaces.size() and spaces[j] == i)
                res.push_back(' '), j++;
            res.push_back(s[i]);
        }
        return res;
    }
};