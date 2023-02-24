class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //Check every row
        for (int i = 0 ; i < 9 ; i++)
        {
            vector <bool> f(10 , 0);
            for (int j = 0 ; j < 9 ; j++)
            {
                if (board[i][j] == '.')
                    continue;
                if (f[board[i][j] - '0'] == 1)
                    return false;
                f[board[i][j] - '0'] = 1;
            }
        }
        //Check every column
         for (int i = 0 ; i < 9 ; i++)
        {
            vector <bool> f(10 , 0);
            for (int j = 0 ; j < 9 ; j++)
            {
                if (board[j][i] == '.')
                    continue;
                if (f[board[j][i] - '0'] == 1)
                    return false;
                f[board[j][i] - '0'] = 1;
            }
        }
        //Check every 3 x 3
        for (int r = 0 ; r < 9 ; r += 3)
        {
            for (int c = 0 ; c < 9 ; c += 3)
            {
                vector <bool> f(10 , 0);
                // Check 3 x 3 staring from (r,c)
                //========================================
                for (int i = r ; i < r + 3 ; i++)
                {
                    for (int j = c ; j < c + 3; j++)
                    {
                         if (board[i][j] == '.')
                             continue;
                         if (f[board[i][j] - '0'] == 1)
                             return false;
                         f[board[i][j] - '0'] = 1;
                    }
                }
                //========================================
            }
        }
        return true;
    }
};