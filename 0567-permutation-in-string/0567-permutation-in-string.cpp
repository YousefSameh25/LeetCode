class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return 0;

        vector < int > frq[s2.size()];
        for ( int i = 0 ; i < s2.size() ; i++)
            frq[i].resize(26, 0);
        
        for (int i = 0; i < s2.size(); i++)
        {
            frq[i][s2[i] - 'a']++;
            if (i == 0)
                continue;
            for (int j = 0 ; j < 26 ; j++)
                frq[i][j] += frq[i - 1][j];
        }
        vector < int > tar(26, 0);
        for(auto &it : s1)
            tar[it - 'a']++;

        for (int i = s1.size() - 1; i < s2.size(); i++)
        {
            vector < int > r = frq[i];
            bool acc = 1;
            if (i == s1.size() - 1)
            {
                for ( int j = 0 ; j < 26; j++)
                {
                    if (r[j] < tar[j])
                    {
                        acc = 0;
                        break;
                    }
                }
            } 
            else
            {
                vector < int > l = frq[i - s1.size()];
                vector < int > temp(26, 0);
                for (int j = 0 ; j < 26 ; j++)
                    temp[j] += r[j] - l[j];
                for ( int j = 0 ; j < 26; j++)
                {
                    if (temp[j] < tar[j])
                    {
                        acc = 0;
                        break;
                    }
                }
            }
            if (acc)
                return 1;
        }
        return 0;
    }
};