class Solution {
public:
    string compressedString(string word) {
        word += "*";
        string com;
        int cnt = 0;
        char c = word[0];
        for (int i = 0 ; i < word.size() ; i++)
        {
            if (c == word[i] and cnt < 9)
                cnt++;
            else
            {
                com.push_back(cnt + '0');
                com.push_back(c);
                cnt = 1;
                c = word[i];
            }
        }
        return com;
    }
};