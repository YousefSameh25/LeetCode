class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        sort (arrays.begin(), arrays.end());
        return arrays.back().back() - arrays[0][0];
    }
};