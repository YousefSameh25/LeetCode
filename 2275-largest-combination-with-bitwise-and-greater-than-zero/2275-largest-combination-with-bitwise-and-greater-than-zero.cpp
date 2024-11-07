class Solution {
public:
    int largestCombination(vector<int>& candidates) 
    {
        vector < int > bits(24, 0);
        for (int i = 0 ; i < candidates.size(); i++)
        {
            for (int b = 0; b < 24; b++)
            {
                if (candidates[i] & (1 << b))
                    bits[b]++;
            }
        }
        int mx = 0;
        for (int i = 0 ; i < 24 ; i++)
        {
            mx = max(mx, bits[i]);
        }
        return mx;
    }
};