class Solution {
public:
    string robotWithString(string s) {
        vector < char > suf (s.size(), 'z');

        char mn = 'z';
        for (int i = s.size() - 1 ; i >= 0; i--)
        {
            mn = min(mn, s[i]);
            suf[i] = mn; 
        }

        string t, paper;

        for (int i = 0 ; i < s.size() ; i++)
        {
            if (suf[i] == s[i])
            {
                t.push_back(s[i]);
                while (i + 1 < s.size() and t.size() and t.back() < suf[i + 1])
                    paper.push_back(t.back()), t.pop_back();
            }
            else
                t.push_back(s[i]);
        }
        while(t.size())
            paper.push_back(t.back()), t.pop_back();
            
        return paper;
    }
};