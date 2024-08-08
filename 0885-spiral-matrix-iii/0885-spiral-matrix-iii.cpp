class Solution {
public:
    bool valid(int i, int j, int n, int m)
    {
        return (i >= 0 and i < n and j > 0 and j < m);
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) 
    {
        vector < vector < int >> ans;
        ans.push_back({rStart, cStart});
        int len = 1, taken = 1;
        while(taken < rows * cols)
        {
            // Move right by len (increase j)
            for (int i = 0; i < len; i++)
            {
                cStart++;
                if (valid(rStart, cStart, rows, cols))
                    ans.push_back({rStart, cStart}), taken++;
            }
            // Move to the down by len (increase i)
            for (int i = 0; i < len; i++)
            {
                rStart++;
                if (valid(rStart, cStart, rows, cols))
                    ans.push_back({rStart, cStart}), taken++;
            }
            len++;
            // Move to the left by len (decrease j)
            for (int i = 0; i < len; i++)
            {
                cStart--;
                if (valid(rStart, cStart, rows, cols))
                    ans.push_back({rStart, cStart}), taken++;
            }
            // Move to the top by len (decrease i)
            for (int i = 0; i < len; i++)
            {
                rStart--;
                if (valid(rStart, cStart, rows, cols))
                    ans.push_back({rStart, cStart}), taken++;
            }
            len++;
        }
        return ans;
    }
};