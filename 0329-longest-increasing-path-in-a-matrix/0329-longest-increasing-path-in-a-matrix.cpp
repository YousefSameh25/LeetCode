class Solution {
public:
    int x[4] = {0 , 0 , 1 , -1} , y[4] = {1 , -1 , 0 , 0} , dp[210][210];
    bool valid (int i , int j , int n , int m)
    {
        return (i < n and j < m and i >= 0 and j >= 0);
    }
    int dfs (int i , int j , vector<vector<int>>& matrix)
    {
        int &ret =  dp[i][j];
        if (~ret)
            return ret;
        ret = 0;
        
        for (int c = 0 ; c < 4 ; c++)
        {
            int chx = i + x[c] , chy = j + y[c];
            if (not valid (chx , chy , matrix.size() , matrix[0].size()))
                continue;
            if (matrix[i][j] >= matrix[chx][chy])
                continue;
            ret = max ( ret ,  dfs(chx , chy , matrix) + 1 );
        }
        return ret;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        memset(dp , -1 , sizeof dp);
        int n = matrix.size() , m = matrix[0].size();
        int mx = 0;
        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 0 ; j < m ; j++)
            {
                int ret = dfs(i , j , matrix); 
                mx = max(ret , mx);
            }
        }
        return mx + 1;
    }
};