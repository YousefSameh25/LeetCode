class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    bool valid(int i, int j, int n, int m)
    {
        return i >= 0 and i < n and j >= 0 and j < m;
    }
    
    
    int dij (int k , vector<vector<int>>& heights)
    {
        priority_queue < vector < int >> pq;
        pq.push({0, 0, 0});
        
        int dis[heights.size()][heights[0].size()];
        pair < int , int > parent[heights.size()][heights[0].size()];
        
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
                
                if (abs(heights[it[1]][it[2]] - heights[ci][cj]) > k)
                    continue;
                
                if (abs(heights[it[1]][it[2]] - heights[ci][cj]) + it[0] < dis[ci][cj])
                {
                    pq.push({-(abs(heights[it[1]][it[2]] - heights[ci][cj]) + it[0]), ci, cj});
                    dis[ci][cj] = abs(heights[it[1]][it[2]] - heights[ci][cj]) + it[0];
                    parent[ci][cj] = make_pair(it[1], it[2]);
                }
            }
        }
        
        
        if (dis[heights.size() - 1][heights[0].size() - 1] == 1e9)
            return -1;
        
        int ans = -1e9;
        int nodei = heights.size() - 1, nodej = heights[0].size() - 1;
        
        while(nodei or nodej)
        {
            auto par = parent[nodei][nodej];
            ans = max(ans, 
                      abs(heights[nodei][nodej] - heights[par.first][par.second]));
            nodei = par.first;
            nodej = par.second;
        }
        return ans;
    }
    
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int l = 0, r = 1e6, ans;
        
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if (dij(mid, heights) != -1)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        
        return ans;  
    }
};