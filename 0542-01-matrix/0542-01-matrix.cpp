class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int n , m;
    bool valid (int x , int y)
    {
        return (x >= 0 and x < n and y >= 0 and y < m);
    }
    vector <vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        n = mat.size(), m = mat[0].size();
        queue <pair <int , int>> q;
        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 0 ; j < m ; j++)
            {
                if (mat[i][j] == 0) 
                    q.push({i,j});
                else 
                    mat[i][j] = -1;
            }
        }
        while(q.size())
        {     
            auto t = q.front();
            q.pop();
            for (int i = 0 ; i < 4 ; i++)
            {
                int chx = t.first + dx[i];
                int chy = t.second + dy[i];
                if (not valid(chx , chy) or mat[chx][chy] != -1)
                    continue;
                mat[chx][chy] = mat[t.first][t.second] + 1;
                q.push({chx , chy});
            }
        }
        return mat;
    }
};