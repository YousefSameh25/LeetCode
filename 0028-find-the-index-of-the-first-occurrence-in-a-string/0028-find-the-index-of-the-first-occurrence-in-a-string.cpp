class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int  n = haystack.size();
        for (int i = 0 ; i + needle.size() - 1 < n ; i++)
        {
            bool va = 1;
            int st = i;
            for (int j = 0 ; j < needle.size() ; j++)
            {
                if (haystack[st] != needle[j])
                {
                    va = 0;
                    break;
                }
                st++;
            }
            if (va)
                return i;
        }
        return -1;
    }
};