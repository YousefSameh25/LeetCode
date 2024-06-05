class Solution {
public:
    string decodeString(string s) {

        stack <char> st;
        
        for (int i = 0 ; i < s.size(); i++)
        {
            if (s[i] != ']')
                st.push(s[i]);
            else 
            {
                string str = "";
                string num = "";
                bool open = 0;
                
                while(st.size())
                {
                    char top = st.top();
                    
                    if (open)
                    {
                        if (top <= 'z' and top >= 'a')
                            break;
                        if (top == '[')
                            break;
                    }
                    
                    st.pop();
                    open |= top == '[';
                    
                    open ? num.push_back(top) : str.push_back(top);
                }
                
                reverse (num.begin(), num.end());
                reverse (str.begin(), str.end());
                
                int r = stoi(num);
                
                string tempS = "";
                
                while(r--)
                {
                    for (auto c : str)
                        tempS.push_back(c);
                }
                
                reverse(tempS.begin(), tempS.end());
                
                while(tempS.size())
                {
                    st.push(tempS.back());
                    tempS.pop_back();
                }
            }
        }
        
        string ans = "";
        while(st.size())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};