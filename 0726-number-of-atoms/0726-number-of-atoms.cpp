class Solution {
public:
    bool isUpper (char c)
    {
        return c >= 'A' and c <= 'Z';
    }
    
    bool isLower (char c)
    {
        return c >= 'a' and c <= 'z';
    }
    
    bool isNumber(char c)
    {
        return c >= '0' and c <= '9';
    }
    
    
    string countOfAtoms(string s) 
    {
        stack < char > st;
        s = "(" + s;
        s.push_back(')');
        
        for (int i = 0 ; i < s.size();)
        {
            if (s[i] == ')')
            {
                string tmp;
                while(st.size() and st.top() != '(')
                    tmp.push_back(st.top()), st.pop();
                
                st.pop();
                
                reverse(tmp.begin(), tmp.end());
                
                //--------------------------------------
                
                string num;
                i++;
                while (i < s.size() and isNumber(s[i]))
                    num.push_back(s[i]), i++;
                
                int number = num.size()? stoi(num) : 1;
                                
                string toBeReturned;
                
                for (int j = 0 ; j < tmp.size();)
                {
                    if (isUpper(tmp[j]))
                    {
                        string sub;
                        sub.push_back(tmp[j]);
                        
                        j++;
                        
                        while (j < tmp.size() and isLower(tmp[j]))
                            sub.push_back(tmp[j]), j++;
                        
                        string subNum;
                        
                        while (j < tmp.size() and isNumber(tmp[j]))
                            subNum.push_back(tmp[j]), j++;
                        
                        if (subNum.empty())
                            subNum = "1";
                        
                        string totalNum = to_string(stoi(subNum) * number);
                        
                        for(auto it : sub)
                            toBeReturned.push_back(it);
                        
                        for (auto it : totalNum)
                            toBeReturned.push_back(it);
                    }
                }
                
                for (auto it : toBeReturned)
                    st.push(it);
                
                
            }
            else 
            {
                st.push(s[i]);
                i++;
            }
        }
        
        
        string ans;
        while(st.size())
            ans.push_back(st.top()), st.pop();
        
        reverse(ans.begin(), ans.end());
        
        map <string , int> mp;
        
        for (int i = 0 ; i < ans.size();)
        {
            if (isUpper(ans[i]))
            {
                string sub;
                sub.push_back(ans[i]);

                i++;

                while (i < ans.size() and isLower(ans[i]))
                    sub.push_back(ans[i]), i++;

                string subNum;

                while (i < ans.size() and isNumber(ans[i]))
                    subNum.push_back(ans[i]), i++;
                
                mp[sub] += stoi(subNum);
            }
        }
        
        string ret;
        
        for (auto it : mp)
        {
            for (auto c : it.first)
                ret.push_back(c);
            
            string frq = to_string(it.second);
            
            if(frq != "1")
            {
                for (auto it2 : frq)
                    ret.push_back(it2);
            }
        }

        return ret;
        
    }
};