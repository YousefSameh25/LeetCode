class Solution {
public:
    vector < string > split(string &s)
    {
        s += " ";
        vector < string > ret;
        string temp;
        for (auto &ch: s)
        {
            if (ch == ' ')
            {
                ret.push_back(temp);
                temp.clear();
            } else {
                temp.push_back(ch);
            }
        }
        return ret;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector < string > a = split(sentence1);
        vector < string > b = split(sentence2);

        int l1 = 0, r1 = a.size() - 1;
        int l2 = 0, r2= b.size() - 1;

        // Common prefix
        while(l1 < a.size() and l2 < b.size() and a[l1] == b[l2])
            l1++, l2++;

        // Common suffix
        while(r1 >= 0 and r2 >= 0 and a[r1] == b[r2])
            r1--, r2--;

        return (l1 > r1 or l2 > r2);
    }
};