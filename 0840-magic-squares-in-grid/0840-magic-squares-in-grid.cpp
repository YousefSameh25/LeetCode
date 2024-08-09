class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid.back().size();
        int ans = 0;
        for (int i = 0 ; i + 2 < n ; i++)
        {
            for (int j = 0 ; j + 2 < m; j++)
            {
                bool valid = 1;
                // Cal sub
                int sumLstR = 0, sumLstC = 0, sumD1 = 0, sumD2 = 0;
                set < int > st;
                for (int k = i; k < i + 3; k++)
                {
                    int sumR = 0;
                    for (int x = j; x < j + 3; x++)
                    {
                        if (grid[k][x] > 9 or !grid[k][x] or st.count(grid[k][x]))
                        {
                            valid = 0;
                            break;
                        }
                        st.insert(grid[k][x]);
                        sumR += grid[k][x];
                    }
                    if (!sumLstR) sumLstR = sumR;
                    else if (sumLstR != sumR)
                    {
                        valid = 0;
                        break;
                    }
                }       

                for (int x = j; x < j + 3; x++)
                {
                    int sumC = 0;
                    for (int k = i; k < i + 3; k++)
                    {
                        if (grid[k][x] > 9 or !grid[k][x])
                        {
                            valid = 0;
                            break;
                        }
                        sumC += grid[k][x];
                    }
                    if (!sumLstC) sumLstC = sumC;
                    else if (sumLstC != sumC)
                    {
                        valid = 0;
                        break;
                    }
                }

                for (int k = 0 ; k < 3; k++)
                {
                    sumD1 += grid[i + k][j + k];
                    sumD2 += grid[(i + 2) - k][(j + 2) - k];
                }
                
                if (valid)
                    ans += sumD1 == sumLstR and sumD1 == sumLstC
                        and sumD2 == sumLstR and sumD2 == sumLstC;
            }
        }
        return ans;
    }
};