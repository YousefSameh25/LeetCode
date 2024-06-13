class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        map <string, int> mp;
        
        for (int i = 0 ; i + 9 < s.size(); i++)
        {
            string tmp;
            for (int j = i; j <= i + 9; j++)
                tmp.push_back(s[j]);
            mp[tmp]++;
        }
        
        
        
        vector < string > ans;
        for (auto it : mp)
        {
            if (it.second > 1)
                ans.push_back(it.first);
        }
        return ans;
    }
};