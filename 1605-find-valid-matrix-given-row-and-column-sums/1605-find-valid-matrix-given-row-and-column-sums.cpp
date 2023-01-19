class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size() , m = colSum.size();
        vector<vector<int>>s(n , vector<int>(m));
        for(int i =0 ; i< min(n,m);i++)
        { 
            int mn = min(rowSum[i] , colSum[i]);
            s[i][i] = mn, rowSum [i] -=mn , colSum[i] -=mn; 
         }
        for(int i = 0;i < n ;i++)
        {
            for(int j = 0; j< m;j++)
            {
                if(i == j)
                    continue;
                int mn = min(rowSum[i] , colSum[j]);
                s[i][j] = mn, rowSum [i] -=mn , colSum[j] -=mn; 
            }
        }
        return s;
    }
};