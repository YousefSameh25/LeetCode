class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        set < int > st;
        int CompleteSet = 0;
        for ( int i = 0 ; i < rolls.size(); i++)
        {
            st.insert(rolls[i]);
            if(st.size() == k)
            {
                CompleteSet++;
                st.clear();
            }
        }
        return CompleteSet + 1;
    }
};