class Solution {
public:
    int minSwaps(string s) {
        vector<int> mp[3];
        
        for (int i = 0 ; i < s.size(); i++)
            mp[s[i] - '['].push_back(i);
        
        stack < char > st;
        
        int ans = 0;
        for (int i = 0 ; i < s.size() ; i++)
        {
            if (st.empty())
            {
                if (s[i] == '[')
                    st.push(s[i]);
                else 
                {
                    swap(s[i], s[mp['['- '['].back()]);
                    mp['['- '['].pop_back();
                    st.push(s[i]);
                    ans++;
                }
            }
            else 
            {
                if (s[i] == ']')
                {
                    if (st.top() == '[')
                        st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        
        return ans;
    }
};