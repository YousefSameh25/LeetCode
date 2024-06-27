class Solution {
public:
        
    char plus(char c)
    {
        if (c == '9')
            return '0';
        return ++c;
    }
    
    char mins(char c)
    {
        if (c == '0')
            return '9';
        return --c;
    }
    
    map < string, int > mp;
    
    int solve (string t, set < string > &st)
    {
        queue < string > q;
        map < string , int > lvl;
        q.push("0000");
        lvl["0000"] = 0;
        while(q.size())
        {
            string node = q.front();
            q.pop();
            
            if (node == t)
                break;
            
            for (int i = 0 ; i < 4 ; i++)
            {
                char c = plus(node[i]);
                string tmp = node;
                tmp[i] = c;
                if (!lvl.count(tmp) and !st.count(tmp))
                {
                    lvl[tmp] = lvl[node] + 1;
                    q.push(tmp);
                }
                
                //----------------------------
                
                c = mins(node[i]);
                tmp = node;
                tmp[i] = c;
                if (!lvl.count(tmp) and !st.count(tmp))
                {
                    lvl[tmp] = lvl[node] + 1;
                    q.push(tmp);
                }
            }
        }
        return lvl.count(t) ? lvl[t] : -1;
    }
    
    
    int openLock(vector<string>& deadends, string target) {
        
        set < string > st;
        for (auto it : deadends)
            st.insert(it);
        
        if (st.count("0000"))
            return -1;
        
        return solve(target, st);
    }
};