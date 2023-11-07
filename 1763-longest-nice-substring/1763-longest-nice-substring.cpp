class Solution {
public:
    
    string ok (int m , string &s)
    {
        vector < int > frq (59, 0);

        for ( int i = 0 ; i + m - 1 < s.size() ; i++)
        {
            if (i == 0) 
            {
                
                for( int j = 0 ; j < m ; j++) 
                    frq[s[j] - 'A']++;
                
                bool ok = 1;
                
                for ( int j = 0; j < 26 ; j++)
                {
                    if (frq[j] and !frq[j + 32])
                        ok = 0;
                    if (!frq[j] and frq[j + 32])
                        ok = 0;
                }
                if  (ok)
                    return s.substr(0 , m);
            
            }
            else 
            {
                frq[s[i - 1] - 'A']--;
                frq[s[i + m - 1] - 'A']++;
                
                 bool ok = 1;
                
                for ( int j = 0; j < 26 ; j++)
                {
                    if (frq[j] and !frq[j + 32])
                        ok = 0;
                    if (!frq[j] and frq[j + 32])
                        ok = 0;
                }
                
                if  (ok)
                    return s.substr(i , m);
            }
        }
        return "";
    }
    string longestNiceSubstring(string s) {
        string ans = "";
        for ( int len = 1 ; len <= s.size() ; len++)
        {
            string res = ok (len , s);
            if (res != "") 
                ans = res;
        }
        return ans;
    }
};