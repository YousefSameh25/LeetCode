class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) 
    {
        if (str2.size() > str1.size())
            return 0;
        
        int i = 0, j = 0;
        while(i < str1.size() and j < str2.size())
        {
            char next = (char)(str1[i] + 1);
            if (next > 'z')
                next = 'a';
            if (str1[i] == str2[j] or str2[j] == next)
            {
                i++, j++;
            }
            else
            {
                i++;
            }
        }
        return j == str2.size();
    }
};