class Solution {
public:
    int dx[4] {0, 0, 1, -1};
    int dy[4] {1, -1, 0, 0};

    bool OutOfBound (int i, int j, int n, int m)
    {
        if (i < 0 or i >= n or j < 0 or j >= m)
            return 1;
        return 0;
    }

    bool valid (int i, int j, int iChild, int jChild, vector < vector < char > > &matrix, int n, int m)
    {
        if (OutOfBound(iChild, jChild, n, m))
            return 0;

        return matrix[iChild][jChild] == '0';
    }

    bool vis[100][100];

    void dfs (int i , int j, vector < vector < char > > &matrix, int n, int m)
    {
        vis[i][j] = 1;
        for (int k = 0; k < 4 ; k++)
        {
            int iChild = i + dx[k], jChild = j + dy[k];
            if (not valid(i, j, iChild, jChild, matrix, n, m) or vis[iChild][jChild])
                continue;
            dfs(iChild, jChild, matrix, n, m);
        }
    }


    int regionsBySlashes(vector<string>& grid) 
    {
        int n = grid.size(), m = grid.back().size();
        vector < vector < char > > matrix(n * 3, vector < char> (m * 3, '0'));
        for (int i = 0, i2 = 0 ; i < n ; i++, i2 += 3)
        {
            for ( int j = 0, j2 = 0 ; j < m ; j++, j2 += 3)
            {
                if (grid[i][j] == '/')
                {
                    matrix[i2][j2 + 2] = '1';
                    matrix[i2 + 1][j2 + 1] = '1';
                    matrix[i2 + 2][j2] = '1';
                }
                else if (grid[i][j] == '\\')
                {
                    matrix[i2][j2] = '1';
                    matrix[i2 + 1][j2 + 1] = '1';
                    matrix[i2 + 2][j2 + 2] = '1';
                }
            }
        }

        int compNum = 0;
        for (int i = 0 ; i < n * 3 ; i++)
        {
            for (int j = 0; j < m * 3; j++)
            {
                cout << matrix[i][j];
                if (vis[i][j] or matrix[i][j] == '1')
                    continue;
                dfs(i, j, matrix, n * 3, m * 3);
                compNum++;
            }
            cout << endl;
        }

        return compNum;
    }
};