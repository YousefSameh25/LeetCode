class Solution {
public:
    vector <string> Grid;
    int n, m;
    int Cmax, Mmax;
    bool validCell (int x , int y)
    {
        if (x > n - 1 or x < 0)
            return 0;
        if (y > m - 1 or y < 0)
            return 0;
        if (Grid[x][y] == '#')
            return 0;
        return 1;
    }
    
    int dp[8 * 8 * 2 + 1][10][10][10][10];
    
    int dir[5] {0, 1, 0, -1, 0};
    
    bool solve (int t , int cx , int cy, int mx, int my)
    {
        if (t > 8 * 8 * 2)
            return 0;
        
        
        if (~dp[t][cx][cy][mx][my])
            return dp[t][cx][cy][mx][my];
        
        
        if (t % 2 == 0)
        {
            for (int d = 0 ; d < 4 ; d++)
            {
                for (int i = 0 ; i <= Mmax; i++)
                {
                    if (validCell(mx + (dir[d] * i), my + (dir[d + 1] * i)))
                    {
                        if (Grid[mx + (dir[d] * i)][my + (dir[d + 1] * i)] == 'F')
                            return dp[t][cx][cy][mx][my] = 1;
                        if (solve(t + 1, cx, cy, mx + (dir[d] * i), my + (dir[d + 1] * i)))
                            return dp[t][cx][cy][mx][my] = 1;
                    }
                    else 
                        break;
                }
            }
            return dp[t][cx][cy][mx][my] = 0;
        }
        else 
        {
            for (int d = 0 ; d < 4 ; d++)
            {
                for (int i = 0 ; i <= Cmax; i++)
                {
                    if (validCell(cx + (dir[d] * i), cy + (dir[d + 1] * i)))
                    {
                        if (Grid[cx + (dir[d] * i)][cy + (dir[d + 1] * i)] == 'F')
                            return dp[t][cx][cy][mx][my] = 0;
                        
                        else if (cx + (dir[d] * i) == mx and cy + (dir[d + 1] * i) == my)
                            return dp[t][cx][cy][mx][my] = 0;
                        
                        else if (!solve(t + 1, cx + (dir[d] * i), cy + (dir[d + 1] * i), mx , my))
                            return dp[t][cx][cy][mx][my] = 0;
                           
                    }
                    else 
                        break;
                }
            }
            return dp[t][cx][cy][mx][my] = 1;
        }
        return 0;
    }
    
    
    
    
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        // 1000 turns is not usefull here.
        Grid = grid;
        n = grid.size();
        m = grid[0].size();
        Cmax =  catJump;
        Mmax = mouseJump;
        memset (dp , -1 , sizeof(dp));
        
        int x1, y1, x2, y2;
        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 0 ; j < m; j++)
            {
                if (Grid[i][j] == 'C')
                    x1 = i, y1 = j;
                
                if (Grid[i][j] == 'M')
                    x2 = i, y2 = j;
            }
        }
        
        return solve(0 , x1, y1, x2, y2);
    }
};