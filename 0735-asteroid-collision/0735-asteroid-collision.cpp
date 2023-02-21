class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack < int > st;
        for (int i = 0 ; i < asteroids.size() ; i++)
        {
            if (asteroids[i] > 0)
                st.push(asteroids[i]);
            else {
                while (st.size() and st.top() > 0 and -asteroids[i] > st.top())
                    st.pop();
                if (st.empty()) st.push(asteroids[i]);
                else if (st.top() == -asteroids[i])
                    st.pop();
                else if (st.top() < -asteroids[i])
                    st.push(asteroids[i]);
            }
        }
        vector < int > ret;
        while (st.size()) ret.push_back(st.top()) , st.pop();
        reverse (ret.begin() , ret.end());
        return ret;
    }
};