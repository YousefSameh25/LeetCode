class Solution {
public:
    int countGoodSubstrings(string s) 
    {
        if (s.size() < 3)
            return 0;
        set < int > st;
        map < char , int > mp;
        st.insert(s[0]), st.insert(s[1]) , st.insert(s[2]);
        mp[s[0]]++, mp[s[1]]++, mp[s[2]]++;
        int ans = st.size() == 3;
        for ( int i = 0 ; i + 3 < s.size() ; i++)
        {
            mp[s[i]]--;
            if (mp[s[i]] == 0)
                st.erase(s[i]);
            
            st.insert(s[i + 3]);
            mp[s[i + 3]]++;
            ans += st.size() == 3;
        }
        
        return ans;
    }
};