class Solution {
public:
    int mostWordsFound(vector<string>& sentences) 
    {
       map <string , int> mp;
       int mx = 0;
       for (auto &it : sentences)
       {
           int f = 0;
           for (auto &c : it)
               f += (c==' ');
           mx = max (mx , f + 1);
       }
        return mx;
    }
};