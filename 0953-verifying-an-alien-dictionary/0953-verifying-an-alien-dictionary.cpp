class Solution {
public:
    int pos[26];
    bool isAlienSorted(vector<string>& words, string order) {
        
        for (int i = 0 ; i < order.size() ; i++)
            pos[order[i] - 'a'] = i;
        
        vector < string > tmp = words;     
        
        sort (tmp.begin() , tmp.end() ,[&] (string & a, string & b) { 
            for (int i = 0 ; i < min (a.size() , b.size()) ; i++)
            {
                if (pos[a[i] - 'a'] < pos[b[i] - 'a'])
                    return true;
                else if (pos[a[i] - 'a'] > pos[b[i] - 'a'])
                    return false;
            }
            return (a.size() < b.size());
        });
        
        
        for (int i = 0 ; i < words.size() ; i++)
        {
            if (tmp[i] != words[i])
                return false;
        }
        return true;
    }
};