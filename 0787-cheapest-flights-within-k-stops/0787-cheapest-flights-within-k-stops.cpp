class Solution {
public:
    
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        k++;
        
        vector <pair <int , int>> G[n];
        
        for (auto it: flights)
            G[it[0]].push_back({it[1], it[2]});
        
        vector <int> dis(n, 1e9);
        queue <vector <int>> pq; // dis - stops - city
        
        dis[src] = 0;
        pq.push({0, 0, src});
        
        while(pq.size())
        {
            vector <int> temp = pq.front();
            pq.pop();
            
            int city = temp[2];
            int stops = temp[1];
            int dist = temp[0];
            
            if (stops + 1 > k)
                continue;
            
            
            for (auto child : G[city])
            {
                if (dis[child.first] > dist + child.second)
                {
                    dis[child.first] = dist + child.second;
                    pq.push({dis[child.first] , stops + 1, child.first});
                }
            }
            
        }
        return dis[dst] == 1e9? -1 : dis[dst];
    }
};