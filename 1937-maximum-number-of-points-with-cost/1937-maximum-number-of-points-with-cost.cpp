const int Fast = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points.back().size();
        vector < long long > Left(m), Right(m);

        vector < vector < long long >> points2(n, vector < long long >(m));

        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < m ; j++)
                points2[i][j] = points[i][j];

        long long ans = -1e18;
        for (int i = 0 ; i < n - 1 ; i++)
        {
            for (int j = 0 ; j < m; j++)
                Left[j] = max(points2[i][j], (j - 1 >= 0 ? Left[j - 1] - 1 : points2[i][j]));
            
            for (int j = m - 1; j >= 0; j--)
                Right[j] = max(points2[i][j], (j + 1 < m? Right[j + 1] - 1 : points2[i][j]));

            for (int j = 0; j < m ; j++)
                points2[i + 1][j] += max(Left[j], Right[j]);
        }
        return *max_element(points2[n - 1].begin(), points2[n - 1].end());
    }
};