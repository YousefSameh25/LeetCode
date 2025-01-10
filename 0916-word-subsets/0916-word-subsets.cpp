class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        vector < vector < int > > wanted(words2.size(), vector < int > (26, 0));
        int j = 0;
        for (auto &w : words2)
        {
            for(auto &c: w)
                wanted[j][c - 'a']++;
            j++;
        }

        vector < string > ans;
        for (auto &w : words1)
        {
            vector < int > exist(26, 0);
            for (auto &c: w) exist[c - 'a']++;
            bool universal = true;

            for ( int k = 0 ; k < words2.size(); k++)
            {
                for (int i = 0 ; i < 26; i++)
                {
                    if (exist[i] < wanted[k][i])
                    {
                        universal = false;
                        break;
                    }
                }
                if (!universal)
                    break;
            }
            if (universal)
                ans.push_back(w);
        }
        return ans;
    }
};