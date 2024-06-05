class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map <vector <int> , int> mpR;
        
        int n = grid.size(), m = grid.back().size();
        
        for (int i = 0 ;  i < n ; i++)
        {
            vector <int> temp;
            for (int j = 0 ; j < m ; j++)
                temp.push_back(grid[i][j]);
            mpR[temp]++;
        }
        
        map <vector <int> , int> mpC;
        
        for (int j = 0 ;  j < m ; j++)
        {
            vector <int> temp;
            for (int i = 0 ; i < n; i++)
                temp.push_back(grid[i][j]);
            mpC[temp]++;
        }
        
        int ans = 0;
        for (auto it : mpR)
            ans += it.second * mpC[it.first];
       
        return ans;
    }
};