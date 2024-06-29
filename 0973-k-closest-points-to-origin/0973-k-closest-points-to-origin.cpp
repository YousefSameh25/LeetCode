class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multimap < double , vector < int > > tmp;
        for (int i = 0 ; i < points.size(); i++)
                tmp.insert({sqrt(pow(points[i][0], 2) + pow(points[i][1], 2)), points[i]});
        
        vector < vector <int>> ans;
        for (auto it : tmp)
        {
            if (!k)
                break;
            ans.push_back(it.second);
            k--;
        }
        return ans;
    }
};