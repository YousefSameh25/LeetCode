class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        map < vector < int > , int > mp;
        for (int i = 0 ; i < n; i++)
        {
            mp[matrix[i]]++;
            for (int j = 0 ; j < matrix[i].size(); j++)
                matrix[i][j] = 1 - matrix[i][j];
            mp[matrix[i]]++;
        }
        int mx = -1;
        for (auto it : mp)
            mx = max(mx, it.second);
        return mx;
    }
};