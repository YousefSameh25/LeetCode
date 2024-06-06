class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, 
                          int start_node, int end_node) 
    {
        /*
            we can construct maximum spanning tree then dfs from s -> e.
            it is wrong X.
            
            Use dij but we can convert success prop.
        */
        
        vector < pair <int, double> > G[n];
        
        for (int i = 0 ;  i < edges.size(); i++)   
        {
            G[edges[i][0]].push_back({edges[i][1], succProb[i]});
            G[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        vector < double > dist(n, 0);
        
        priority_queue < pair <double , int>> pq;
        
        dist[start_node] = 1.0;
        pq.push({1.00, start_node});
        
        while(pq.size())
        {
            auto top = pq.top();
            pq.pop();
            
            int node = top.second;
            double dis = top.first;
            
            
            for (auto child : G[node])
            {
                if (dist[child.first] < dis * child.second)
                {
                    dist[child.first] = dis * child.second;
                    pq.push({dist[child.first], child.first});
                }
            }
        }
        
        return dist[end_node];
    }
};