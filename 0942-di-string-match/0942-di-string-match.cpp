class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector < int > ans;
        int l = 0 , r = s.size();
        for (int i = 0 ; i < s.size() ; i++)
        {
           if (s[i] == 'I')
               ans.push_back(l++);
           else
               ans.push_back(r--);
        }
        if (l >= 0)
            ans.push_back(l);
        else
            ans.push_back(r);
        return ans;
    }
};