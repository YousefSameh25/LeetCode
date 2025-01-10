class Solution {
public:
    int prefixCount(vector<string>& words, string pref) 
    {
        int ans = 0;
        for (int i = 0 ; i < words.size(); i++)
        {
            ans += words[i].find(pref) == 0;
        }
        return ans;
    }
};