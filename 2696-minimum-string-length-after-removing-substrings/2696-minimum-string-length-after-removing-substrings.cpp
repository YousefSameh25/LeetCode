class Solution {
public:
    int minLength(string s) {
        stack < char > st;
        
        for (int i = 0 ; i < s.size(); i++)
        {
            if (s[i] != 'B' and s[i] != 'D')
                st.push(s[i]);
            else
            {
                if (s[i] == 'B')
                {
                    if (st.size() and st.top() == 'A')
                        st.pop();
                    else  
                        st.push(s[i]);
                }
                else if (s[i] == 'D')
                {
                    if (st.size() and st.top() == 'C')
                        st.pop();
                    else  
                        st.push(s[i]);
                }
            }
        }

        return st.size();
    }
};