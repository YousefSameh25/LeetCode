class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0 ; i < n ; i++)
        {
            vector < bool > f (n + 1,  0);
            int c = 0;
            for (int j = 0 ; j < n ; j++)
            {
                if (not f[matrix[i][j]])
                    c++ , f[matrix[i][j]] = 1;
            }
            if (c != n)
                return false;
        }
        for (int i = 0 ; i < n ; i++)
        {
            vector < bool > f (n + 1,  0);
            int c = 0;
            for (int j = 0 ; j < n ; j++)
            {
                if (not f[matrix[j][i]])
                    c++ , f[matrix[j][i]] = 1;
            }
            if (c != n)
                return false;
        }
        return true;
    }
};