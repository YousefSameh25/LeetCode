class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) 
    {
        vector < pair < int , int > > v;
        int n = values.size();
        for ( int i = 0 ; i < n ; i++)
            v.push_back({values[i], labels[i]});
        sort(v.begin(), v.end(), greater<>());
        vector < int > ava(2e4 + 10, useLimit);
        int ans = 0;
        for ( int i = 0 ; i < n and numWanted ; i++)
        {
            if (ava[v[i].second])
            {
                ava[v[i].second]--;
                ans += v[i].first;
                numWanted--;
            }
        }
        return ans;
    }
};