class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries)
    {
        
        vector < int > ret;
        for (auto & c : queries)
        {
            int ans = 0;
            for ( auto & it : points)
            {
                if (hypot (it[0] - c[0] , it[1] - c[1]) <= c[2])
                    ans++;
            }
            ret.push_back(ans);
        }
        return ret;
    }
};