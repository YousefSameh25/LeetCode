class Solution {
public:
    double dp[1001][1001];
    int s;
    double solve(int i, int skips, vector<int> &dist) {
        if (i < 0)
            return 0;

        double &ret = dp[i][skips];

        if (dp[i][skips] != 0)
            return ret;

        double time = (double) dist[i] / s;
        ret = ceil ((double)solve(i - 1, skips, dist) + time);
        if (skips)
            ret = min(ret, solve(i - 1, skips - 1, dist) + time - 1e-9);


        return ret;
    }
    
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        s = speed;
        
        
        for (int i = 0 ; i < dist.size() ; i++)
            for (int j = 0 ; j < dist.size() ; j++)
                dp[i][j] = 0;
        
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