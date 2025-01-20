class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat.back().size();
        unordered_map < int , stack < pair < int , int >>> mp;
        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < m ; j++)
                mp[mat[i][j]].push({i , j});

        vector < int > row(n, 0), col(m, 0);

        for (int i = 0 ; i < n * m ; i++)
        {
            int val = arr[i];
            while(mp[val].size())
            {
                auto pr = mp[val].top();
                row[pr.first]++;
                col[pr.second]++;
                if (row[pr.first] == m)
                    return i;
                if (col[pr.second] == n)
                    return i;
                mp[val].pop();
            }
        }
        return 404;
    }
};