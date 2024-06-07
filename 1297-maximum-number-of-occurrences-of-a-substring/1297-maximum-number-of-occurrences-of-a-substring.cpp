class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) 
    {
        unordered_map <string , int> mp;
        for (int i = 0 ; i < s.size() ; i++)
        {
            set <char> st;
            string str;
            
            for (int j = i ; j < s.size(); j++)
            {
                st.insert(s[j]);
                str.push_back(s[j]);
                
                if (st.size() > maxLetters or str.size() > maxSize)
                    break;
                
                if (str.size() >= minSize)
                    mp[str]++;
            }
        }
        
        int ans = 0;
        for (auto it : mp)
            ans = max(ans, it.second);
        
        return ans;
    }
};