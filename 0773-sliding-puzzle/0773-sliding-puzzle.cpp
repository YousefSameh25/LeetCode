class Solution {
public:
    bool ok(vector<vector<int>>& board)
    {
        int x = 1;
        bool b = 1;
        for (int i = 0 ; i < 2 ; i++)
        {
            for (int j = 0 ; j < 3; j++)
            {
                x %= 6;
                cout << board[i][j] << " ";
                if (board[i][j] != x)
                {
                    b = 0;
                }
                x++;
            }
            cout << endl;
        }
        cout << "-----------\n";
        return b;
    }
    bool valid(int i, int j, int n, int m)
    {
        return i >= 0 and i < n and j >= 0 and j < m;
    }
    map < vector < vector < int >>, int > st;

    void solve(int i, int j, vector<vector<int>> &board, int moves)
    {
        if (st.count(board) and moves >= st[board])
        {
            return;
        }

        st[board] = moves;

        if (valid(i + 1, j, board.size(), board.back().size()))
        {
            swap(board[i][j], board[i + 1][j]);
            solve(i + 1, j, board, moves+ 1);
            swap(board[i][j], board[i + 1][j]);
        }
        if (valid(i, j + 1, board.size(), board.back().size()))
        {
            swap(board[i][j], board[i][j + 1]);
            solve(i, j + 1, board, moves+ 1);
            swap(board[i][j], board[i][j + 1]);
        }
        if (valid(i - 1, j, board.size(), board.back().size()))
        {
            swap(board[i][j], board[i - 1][j]);
            solve(i - 1, j, board, moves+ 1);
            swap(board[i][j], board[i - 1][j]);
        }
        if (valid(i , j - 1, board.size(), board.back().size()))
        {
            swap(board[i][j], board[i][j - 1]);
            solve(i, j - 1, board, moves+ 1);
            swap(board[i][j], board[i][j - 1]);
        }

    }
    int slidingPuzzle(vector<vector<int>>& board) {

        for (int i = 0 ; i < 2 ; i++)
        {
            for (int j = 0 ; j < 3; j++)
            {
                if (!board[i][j])
                {
                    solve(i, j ,board, 0);
                    break;
                }
            }
        }

        return st.count({{1,2,3},{4,5,0}}) ? st[{{1,2,3},{4,5,0}}] : -1;
    }
};