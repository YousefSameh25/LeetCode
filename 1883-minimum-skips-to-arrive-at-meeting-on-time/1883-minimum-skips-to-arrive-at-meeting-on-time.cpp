class Solution {
public:
    double dp[1001][1001];
    int vis[1001][1001] , s;
    int ceiling(double a)
    {
	int ret=a;
	if(ret==a)
		return ret;
	else return ret+1;
    }
    double solve(int i, int skips, vector<int> &dist) {
        if (i < 0)
            return 0;

        double &ret = dp[i][skips];

        if (dp[i][skips] != 0)
            return ret;

        double time = (double) dist[i] / s;
        ret = (int) ceiling ((double)solve(i - 1, skips, dist) + time);
        if (skips)
            ret = min(ret, solve(i - 1, skips - 1, dist) + time - (1e-8));

        vis[i][skips] = 1;
        return ret;
    }
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        s = speed;
        memset (dp , 0 , sizeof dp);
        memset (vis , 0 , sizeof vis);
        
        //  for (int sk = 0; sk < dist.size(); sk++)
        // if (solve(dist.size() - 1, sk, dist) <= 1.0 * hoursBefore) {
        //     return sk;
        // }
        // return -1;
        int l = 0 , r = dist.size() - 1 , ans = -1;
        while( l <= r )
        {
            int mid =  (l + r) / 2;
            if (solve (dist.size() - 1 , mid , dist) <= 1.0 * hoursBefore)
                ans = mid , r = mid - 1;
            else
                l = mid + 1; 
        }
        return ans;
    }
};