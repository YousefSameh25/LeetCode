class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix.back().size();
        vector<vector<int>> onesUnderMe(n , vector <int> (m , 0));
        for (int j = 0 ; j < m ; j++)
        {
            for (int i = n - 1 ; i >= 0 ; i--)
            {
                if (matrix[i][j] == 0)
                    continue;
                if (i + 1 < n)
                    onesUnderMe[i][j] += onesUnderMe[i + 1][j] + 1;
                else 
                    onesUnderMe[i][j] = 1;
            }
        }
        
        int ans = 0;
        for (int i = 0 ; i < n ; i++)
        {
           sort(onesUnderMe[i].begin() , onesUnderMe[i].end());
            for (int j = 0 ; j < m ; j++)
                ans = max(ans , onesUnderMe[i][j] * (m - j));
        }
        return ans;
    }
};