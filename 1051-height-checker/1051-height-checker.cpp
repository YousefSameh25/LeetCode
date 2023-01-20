class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ret = 0;
        vector <int> v = heights;
        sort(v.begin() , v.end());
        for (int i = 0 ; i < v.size() ; i++)
            ret += (v[i] != heights[i]);
        return ret;
    }
};