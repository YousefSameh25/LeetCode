class Solution {
public:
    int MOD = 1e9+7;
    int arr[4][4]={{1 , 2, 3} , {4 ,5 ,6 } , {7 ,8 , 9}, {10 ,0 , 11}};
    int dx[9] = {1  , 1 , -1 , -1 , 2 ,2 ,-2 ,-2};
    int dy[9] ={-2 , 2 , -2 ,  2 , 1 ,-1,  1,-1};
    bool valid(int x , int y )
    {
        return( x >= 0 and x <= 3 and y>= 0 and y<=2 and arr[x][y] <= 9 );
    }
    int dp[5000+10][10][10];
    int solve(int n , int x , int y)
    {
        if(n == 0)
            return 1;
        int &res = dp[n][x][y];
        if(~res)
            return res;
        res = 0;
        for(int i = 0 ; i <= 7 ;i++)
        {
            int nx = x + dx[i] , ny = y + dy[i];
            if(valid(nx , ny))
                res = ((res % MOD) + (solve(n -1 , nx , ny) %MOD))%MOD;
        }
        return res;
    }
    int knightDialer(int n) {
        memset(dp , -1 , sizeof dp);
        int res = 0; 
        for(int i = 0 ; i <= 3 ;i++)
            for(int j =0 ; j < 3 ;j++)
                if(valid(i ,j))
                  res = ((res % MOD) + (solve(n -1 , i , j) %MOD))%MOD;
        return res;
    }
};