class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) 
    {
        vector < vector < int >> v;
        for (int i = 0 ; i < positions.size(); i++)
            v.push_back({positions[i], healths[i], directions[i] == 'R'? 0 : 1});
        
        sort(v.begin(), v.end());
        
        
        stack < vector < int > > st;
        
        map < int , int > mp;

        
        for (auto it : v)
        {
            int pos = it[0];
            int health = it[1];
            int dir = it[2];
            if (dir == 0)
            {
                mp[pos] = health;
                st.push({pos , dir, health});
            }
            else
            {
                bool will = 1;
                while(st.size())
                {
                    if (health == st.top()[2])
                    {
                        mp.erase(st.top()[0]);
                        mp.erase(pos);
                        st.pop();
                        will = 0;
                        break;
                    }
                    else if (health > st.top()[2])
                    {
                        mp.erase(st.top()[0]);
                        health--;
                        st.pop();
                    } 
                    else 
                    {
                        auto top = st.top();
                        mp[st.top()[0]]--;
                        
                        st.pop();
                        top[2]--;
                        st.push(top);
                        will = 0;
                        break;
                    }
                }
                if (will)
                    mp[pos] = health;
                
            }
        }
        
        
        vector < int > ans;
        for (auto it : positions)
        {
            if (mp.count(it))
                ans.push_back(mp[it]);
        }
            
        return ans;
        
    }
};