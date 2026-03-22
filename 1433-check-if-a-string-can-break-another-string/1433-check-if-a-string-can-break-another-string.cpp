class Solution {
    private: 
    bool Check(string& a, string& b)
    {
        bool ok = 1;
        for(int i = 0 ; i < a.size(); i++)
        {
            ok &= a[i] >= b[i];
            if (!ok)
                break;
        }
        return ok;
    } 
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        reverse(s2.begin(), s2.end());
        reverse(s1.begin(), s1.end());
        
        return Check(s1, s2) || Check(s2, s1);
    }
};