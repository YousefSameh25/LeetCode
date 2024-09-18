class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        s1 += " ", s2 += " ";
        unordered_map < string , int > st;
        string word;
        for (int i = 0 ; i < s1.size(); i++)
        {
            if (s1[i] == ' ') {
                st[word]++;
                word = "";
            }
            else
                word.push_back(s1[i]);
        }

        for (int i = 0 ; i < s2.size(); i++)
        {
            if (s2[i] == ' ') {
                st[word]++;
                word = "";
            }
            else
                word.push_back(s2[i]);
        }
        vector < string > ans;
        for (auto it : st)
        {
            if (it.second == 1)
                ans.push_back(it.first);
        }
        return ans;
    }
};