class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0 ; j < n; j++)
            {
                if (i == j)
                    break;
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
        
        
        for (auto &it : matrix)
           reverse(it.begin(), it.end());
         
    }
};