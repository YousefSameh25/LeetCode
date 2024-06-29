class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    bool valid(int i, int j, int n, int m)
    {
        return i >= 0 and i < n and j >= 0 and j < m;
    }
    
    
    int dij (vector<vector<int>>& heights)
    {
        priority_queue < vector < int >> pq;
        pq.push({0, 0, 0});
        
        int dis[heights.size()][heights[0].size()];
        
        for (int i = 0 ; i < heights.size(); i++)
            for (int j = 0; j < heights[0].size(); j++)
                dis[i][j] = 1e9;
        
        dis[0][0] = 0;
        
        while(pq.size())
        {
            auto it = pq.top();
            pq.pop();
            it[0] *= -1;
            
            if (it[0] > dis[it[1]][it[2]])
                continue;
            
            for (int x = 0 ; x < 4 ; x++)
            {
                int ci = dx[x] + it[1];
                int cj = dy[x] + it[2];
                
                if (!valid(ci, cj, heights.size(), heights[0].size()))
                    continue;
                
                int newDis = max(abs(heights[it[1]][it[2]] - heights[ci][cj]), it[0]);
                if (newDis < dis[ci][cj])
                {
                    pq.push({-newDis, ci, cj});
                    dis[ci][cj] = newDis;
                }
            }
        }
        
        
       return dis[heights.size() - 1 ][heights[0].size() - 1];
    }
    
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        return dij(heights);
    }
};