class Solution {
public:
    bool isPrefix(string &a, string &b)
    {
        if (a.size() < b.size())
            return 0;
        for (int i = 0 ; i < b.size(); i++)
        {
            if (a[i] != b[i])
                return 0;
        }
        return 1;
    }
    int isPrefixOfWord(string sentence, string searchWord) 
    {
        sentence.push_back(' ');
        string word;
        int cnt = 1;
        for (int i = 0 ; i < sentence.size(); i++)
        {
            if (sentence[i] == ' ')
            {
                if (isPrefix(word, searchWord))
                    return cnt;
                cnt++;
                word.clear();
            }
            else
            {
                word.push_back(sentence[i]);
            }
        }
        return -1;
    }
};