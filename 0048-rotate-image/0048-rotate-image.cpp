class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        set <vector <int>> pos;
        
        int newi = 0, newj = n - 1;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0 ; j < n ; j++)
            {
                pos.insert({matrix[i][j], newi , newj});
                newi += 1, newi %= n;
            }
            newj--;
        }
        
        
        for (auto it : pos)
            matrix[it[1]][it[2]] = it[0];
         
    }
};