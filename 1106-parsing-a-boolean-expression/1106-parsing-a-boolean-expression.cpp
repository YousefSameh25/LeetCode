class Solution {
public:
    bool parseBoolExpr(string ex) 
    {
        stack < char > st;
        for (int i = 0 ; i < ex.size(); i++)
        {
            if (ex[i] == ')')
            {
                string temp = "";
                while(st.top() != '(')
                    temp.push_back(st.top()), st.pop();
                
                st.pop();

                char op = st.top();
                st.pop();

                int f  = 0, t = 0;
                for (auto it : temp)
                    it == 'f'? f++ : t++;

                char ans;

                if (op == '|')
                    ans = t? 't' : 'f';
                else if (op == '&')
                    ans = !f ? 't' : 'f';
                else 
                    ans = f ? 't' : 'f';

                st.push(ans);
            }
            else if (ex[i] != ',')
            {
                st.push(ex[i]);
            }
        }
        return st.top() == 't';
    }
};