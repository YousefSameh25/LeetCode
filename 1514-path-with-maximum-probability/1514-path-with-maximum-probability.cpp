class Solution {
public:
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> graph[n];  // node(u)--> {node(v),prob};
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
 
           vector<int> vis(n,0);
          priority_queue<pair<double,int>> pq;
          vector<double> dist(n,0);
          pq.push({1.00,start});

           while(!pq.empty()){
               auto top=pq.top();
               pq.pop();
               int node=top.second;
               double currdist=top.first;
                vis[node]=1;
               for(auto x:graph[node]){
                   int child= x.first;
                   double pathprob=x.second;

                   if(vis[child]==0){
                        if(currdist*pathprob>dist[child]){
                            dist[child]= currdist*pathprob;
                            pq.push({dist[child],child});
                        }
                   }
               }

           }
           return dist[end];

    }
};