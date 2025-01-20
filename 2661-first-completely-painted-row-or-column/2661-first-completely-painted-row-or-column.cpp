class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat.back().size();
        unordered_map < int , vector < pair < int , int >>> mp;
        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < m ; j++)
                mp[mat[i][j]].push_back({i , j});
        vector < int > row(n, 0), col(m, 0);

        for (int i = 0 ; i < n * m ; i++)
        {
            int val = arr[i];
            while(mp[val].size())
            {
                row[mp[val].back().first]++;
                col[mp[val].back().second]++;
                if (row[mp[val].back().first] == m)
                    return i;
                if (col[mp[val].back().second] == n)
                    return i;
                mp[val].pop_back();
            }
        }
        return 404;
    }
};