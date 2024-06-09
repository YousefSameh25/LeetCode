class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        vector <vector <int>> v; 
        
        for (auto it : intervals)
            v.push_back({it[1], it[0]});
        
        sort(v.begin(), v.end());
        
        int r = v[0][0];
        int ans = 1;
        cout << r << endl;
        for (int i = 1 ; i < v.size(); i++)
        {
           if (v[i][1] >= r)
               ans++, r = v[i][0];
        }
        return intervals.size() - ans;
    }
};