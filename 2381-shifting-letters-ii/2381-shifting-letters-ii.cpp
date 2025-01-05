class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) 
    {
        vector < int > pre(s.size() + 1, 0);
        for (auto r : shifts)
        {
            if (r[2] == 0) r[2] = -1;

            pre[r[0]] += r[2];
            pre[r[1] + 1] += r[2] * -1;
        }
        for (int i = 1; i < s.size(); i++)
            pre[i] += pre[i - 1];

        for (int i = 0 ; i < s.size(); i++)
        {
            int newC = ((int)(s[i] - 'a')) + pre[i];
            newC = ((newC % 26) + 26) % 26;
            s[i] = ((char)(newC + 'a'));
        }
        return s;
    }
};