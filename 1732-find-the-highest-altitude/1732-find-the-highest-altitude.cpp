class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        int prv = 0, mx = 0;
        for (int i = 0 ; i < gain.size() ; i++)
        {
            int cur = prv + gain[i];
            prv = cur;
            mx = max(mx, prv);
        }
        return mx;
    }
};