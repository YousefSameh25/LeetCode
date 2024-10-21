class Solution {
public:
    int maxUniqueSplit(string s) 
    {
       int ans = 0, n = s.size() - 1;
       for (int msk = 0; msk < (1 << n); msk++)
       {
            string temp;
            unordered_set < string > st;
            temp.push_back(s[0]);
            for (int i = 0 ; i < n ; i++)
            {
                if (msk & (1 << i))
                {
                    st.insert(temp);
                    temp.clear();
                    temp.push_back(s[i + 1]);
                }
                else
                {
                    temp.push_back(s[i + 1]);
                }
            }
            st.insert(temp);
            ans = max(ans, (int)st.size());
       } 
       return ans;
    }
};