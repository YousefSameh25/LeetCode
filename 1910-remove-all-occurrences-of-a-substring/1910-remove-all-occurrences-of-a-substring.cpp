class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack < char > st;
        for (auto &it : s)
        {
            st.push(it);
            if (st.size() < part.size())
                continue;
            string temp;
            while(st.size() and temp.size() != part.size())
                temp.push_back(st.top()), st.pop();
            reverse(temp.begin(), temp.end());
            if (temp != part)
            {
                for(auto c: temp)
                    st.push(c);
            }
        }
        string res;
        while(st.size())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};