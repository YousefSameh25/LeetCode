class Solution {
private: 
    int sum(int i, int j, int x, int y, vector<vector<int>>& mat)
    {
        int s = mat[x][y];

        if (i - 1 < mat.size())
            s -= mat[i - 1][y];

        if (j - 1 < mat.back().size())
            s -= mat[x][j - 1];

        if (i - 1 < mat.size() and j - 1 < mat.back().size())
            s += mat[i - 1][j - 1];

        return s;
    }
public:
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat.back().size();
        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 1; j < m ; j++)
                mat[i][j] += mat[i][j - 1];
        }

        for (int j = 0 ; j < m ; j++)
        {
            for (int i = 1; i < n ; i++)
                mat[i][j] += mat[i - 1][j];
        }

        int ans = 0;
        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 0; j < m ; j++)
            {
                // Try all lengths
                int x = i, y = j;
                while(x < n and y < m)
                {
                    int a = (x - i + 1) * (y - j + 1);
                    ans += sum(i, j, x, y, mat) == a;
                    x++, y++;
                }
            }
        }
        return ans;
    }
};