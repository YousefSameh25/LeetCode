class Solution {
public:
    bool valid (int i , int j, int n, int m)
    {
        return i >= 0 and i < n and j >= 0 and j < m;
    }
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0}; 
    int Dijkstra (vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid.back().size();

        vector < vector < int >> dist(n, vector < int > (m, 1e9));
        dist[0][0] = 0;
        priority_queue < pair < int , pair < int , int > >> pq;
        pq.push({0, {0, 0}});

        while (pq.size())
        {
            auto it = pq.top();
            pq.pop();
            int nodei = it.second.first;
            int nodej = it.second.second;
            int curCost = -it.first;


            if (curCost > dist[nodei][nodej])
                continue;

            for (int i = 0 ; i < 4 ; i++)
            {
                int childi = nodei + dx[i], childj = nodej + dy[i];
                if (!valid(childi, childj, n, m))
                    continue;
                if (curCost + grid[childi][childj] < dist[childi][childj])
                {
                    dist[childi][childj] = curCost + grid[childi][childj];
                    pq.push({-dist[childi][childj],{childi, childj}});
                }
            }
        }
        return dist[n - 1][m - 1];
    }


    int minimumObstacles(vector<vector<int>>& grid) {
        return Dijkstra(grid);
    }
};