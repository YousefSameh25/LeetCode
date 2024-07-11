class Solution {
public:
    string reverseParentheses(string s) {
        stack < char > st;
        for (int i = 0 ; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);  
            }   
            else if(s[i] == ')')
            {
                string word;
                while(st.size() and st.top() != '(')
                    word.push_back(st.top()), st.pop();
                
                st.pop();
                
                for (auto it : word)
                    st.push(it);
                                
            } 
            else
                st.push(s[i]);
        }
        
        string ret;
        while(st.size())
            ret.push_back(st.top()), st.pop();
        
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};