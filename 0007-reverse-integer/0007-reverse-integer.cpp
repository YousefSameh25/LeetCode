class Solution {
    
public:
    int reverse(int x) {
    string s = to_string(x) , t;
        
    for (int i = s.size() - 1 ; i >= 0 ; i--)
    {
        if (s[i] != '-')
           t.push_back(s[i]);
    }
    
    if ( INT32_MIN <= 1LL * stoll(t) and 1LL * stoll(t) <= INT32_MAX )
    {
        if (s[0] == '-')
            return -1LL * stoll(t);
        return 1LL * stoll(t);
    }
    return 0;
    }
};