class Solution {
public:
    int minSwaps(string s) {
        vector < int > idx;
        for (int i = 0 ; i < s.size() ; i++)
            if (s[i] == '[')
                idx.push_back(i);

        stack < char > st;
        int ans = 0;
        for (int i = 0; i < s.size() ; i++)
        {
            if (s[i] == '[')
                st.push(s[i]);
            else
            {
                if (st.size())
                    st.pop();
                else
                {
                    swap(s[i], s[idx.back()]);
                    idx.pop_back();
                    ans++;
                    st.push(s[i]);
                }
            }
        } 
        return ans; 
    }
};