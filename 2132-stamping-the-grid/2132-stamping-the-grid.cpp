class Solution {
public:
     int dix[4] = { 0 , 0 , 1 , -1 }, diy[4] = { 1 , -1 , 0 , 0 };
    bool valid(int i, int j, int n, int m)
    {
        return (i < n and i >= 0 and j < m and j >= 0);
    }
    int query(vector <vector <int>>& pre, int x, int y, int h, int w, int n, int m)
    {
        int ans = pre[x][y];
        if (valid(x - h, y, n, m))
            ans -= pre[x - h][y];

        if (valid(x, y - w, n, m))
            ans -= pre[x][y - w];

        if (valid(x - h, y - w, n, m))
            ans += pre[x - h][y - w];

        return ans;
    }

    bool possibleToStamp(vector<vector<int>>& grid, int h, int w)
    {
        int n = grid.size(), m = grid[0].size();



        vector<vector<int>> pre(n, vector< int >(m, 0));
        vector < vector < int > > x_pos;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    x_pos.push_back({ i , j });
            }

        }
        if(x_pos.size() == n*m)
            return true;

        if(h > n || w > m)
            return false;

                //if (grid[i][j] == 1)
                  //  x_pos.push_back({ i , j });

        pre[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
            pre[0][i] = pre[0][i - 1] + grid[0][i];
        for (int i = 1; i < n; i++)
            pre[i][0] = pre[i - 1][0] + grid[i][0];

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++)

                pre[i][j] = pre[i - 1][j] + pre[i][j - 1]
                - pre[i - 1][j - 1] + grid[i][j];
        }

        for (auto& pos : x_pos)
        {
            for (int k = 0; k < 4; k++)
            {
                int cx = pos[0] + dix[k], cy = pos[1] + diy[k];
                if (not valid(cx, cy, n, m) or grid[cx][cy] != 0)
                    continue;
                bool ok = 0;
                // case 1
                int x = cx + h - 1, y = cy + w - 1;

                if (valid(x, y, n, m))
                    if (query(pre, x, y, h, w, n, m) == 0 and valid(x - h + 1, y - w + 1, n, m)) {
                        for (int row = x - h + 1; row <= x; row++) {

                            for (int col = y - w + 1; col <= y; col++)

                                grid[row][col] = 2;
                        }
                    }
                // case 2
                y = cy;
                if (valid(x, y, n, m))
                    if (query(pre, x, y, h, w, n, m) == 0 and valid(x - h + 1, y - w + 1, n, m)) {
                        for (int row = x - h + 1; row <= x; row++) {

                            for (int col = y - w + 1; col <= y; col++)
                                grid[row][col] = 2;
                        }
                    }
                //          // case 3
                x = cx, y = cy + w - 1;
                if (valid(x, y, n, m))
                    if (query(pre, x, y, h, w, n, m) == 0 and valid(x - h + 1, y - w + 1, n, m)) {
                        for (int row = x - h + 1; row <= x; row++) {

                            for (int col = y - w + 1; col <= y; col++)
                                grid[row][col] = 2;
                        }
                    }
                //          //case 4
                x = cx, y = cy;
                if (valid(x, y, n, m))
                    if (query(pre, x, y, h, w, n, m) == 0 and valid(x - h + 1, y - w + 1, n, m)) {

                        for (int row = x - h + 1; row <= x; row++) {

                            for (int col = y - w + 1; col <= y; col++)
                                grid[row][col] = 2;
                        }
                    }
            }

        }
        for (auto& pos : x_pos)
        {
            for (int k = 0; k < 4; k++) {
                int cx = pos[0] + dix[k], cy = pos[1] + diy[k];
                if (valid(cx, cy, n, m) and grid[cx][cy] == 0) {
                    return false;
                }
            }
        }
        return true;
    }
};
