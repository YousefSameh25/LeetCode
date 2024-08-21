class Solution {
public:
    int strangePrinter(string s) {
        set < char > st;
        for (auto it : s)
            st.insert(it);
        return st.size();
    }
};