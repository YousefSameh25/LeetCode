class Solution {
public:
    
    int calc (string &s, string sub, int p)
    {
        int sum = 0;
        stack < char > st;
        for (int i = 0 ; i < s.size(); i++)
        {
            if (sub[1] == s[i])
            {
                if (st.size() and st.top() == sub[0])
                    st.pop(), sum += p;
                else
                    st.push(s[i]);
            } else
                st.push(s[i]);
        }
    
        
        string newS;
        while(st.size())
        {
            newS.push_back(st.top());
            st.pop();
        }
        
        reverse(newS.begin(), newS.end());
        
        s = newS;
                
        return sum;
    }
    
    
    
    int maximumGain(string s, int x, int y) 
    {
        if (x > y)
            return calc(s, "ab", x) + calc(s, "ba", y);
        
        return calc(s, "ba", y) + calc(s, "ab", x);
    }
    
};