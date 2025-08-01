class Solution {

private:
    int getValue(int i, int j, vector < vector < int >> &pascal)
    {
        return (i >= 0 and i < pascal.size() and j >= 0 and j < pascal[i].size()) ? pascal[i][j] : 0;
    }

public:
    vector<vector<int>> generate(int numRows) 
    {
        vector < vector < int >> pascal(numRows);

        for (int i = 0 ; i < numRows; i++)
        {
            pascal[i].resize(i + 1);
            for (int j = 0 ; j < pascal[i].size(); j++)
            {
                int val = getValue(i - 1, j, pascal) + getValue(i - 1, j - 1, pascal);
                val = max(val , 1);
                pascal[i][j] = val;
            }
        }
        return pascal;
    }
};