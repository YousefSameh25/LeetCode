class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector < int > v(1000000 + 10, 0);
        for (int i = 0 ; i < intervals.size() ; i++)
        {
            v[intervals[i][0]]++;
            v[intervals[i][1] + 1]--;
        }

        int mx = v[0];
        for(int i = 1 ; i < v.size() ; i++)
            v[i] += v[i - 1], mx = max(mx , v[i]);
        
        return mx;
    }
};