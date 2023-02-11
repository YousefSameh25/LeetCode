class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        
        int n = min(str1.size() , str2.size());
        
        int mx = 0;
        
        for (int i = n ; i >= 1 ; i--)
        {
            if (str1.size() % i or str2.size() % i)
                continue;
            
            string tmp = str1.substr(0 , i);
            
            bool g = 1;
            for (int j = 0 ; j + i <= str1.size() ; j += i)
            {
                g &= (str1.substr(j , i) == tmp);
            }
             for (int j = 0 ; j + i <= str2.size() ; j += i)
            {
                g &= (str2.substr(j , i) == tmp);
            }
            if (g)
            {
                mx = i;
                break;
            }
        }
        return str1.substr(0 , mx);
    }
};