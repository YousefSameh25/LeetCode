class Solution {
public:
    int numSplits(string s) {
        set <char> st;
        vector <int> pre(s.size() , 0) , suf(s.size() , 0);
        for (int i = 0 ;i < s.size() ; i++)
        {
            st.insert(s[i]);
            pre[i] = st.size();
        }
        st.clear();
        for (int i = s.size() - 1 ; i >= 0 ; i--)
        {
            st.insert(s[i]);
            suf[i] = st.size();
        }
        int ret = 0;
        for (int i = 0 ; i < s.size() - 1 ; i++)
            ret += (pre[i] == suf[i + 1]);
        return ret;
    }
};