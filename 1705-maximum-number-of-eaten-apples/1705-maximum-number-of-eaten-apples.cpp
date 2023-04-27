class Solution {
public:
    int eatenApples(vector<int>& a, vector<int>& d) 
    {
       priority_queue < pair < int , int > > pq;
       int cur = 0 , i = 0;
       for ( ; i < a.size() ; i++)
       {
           if (a[i])
              pq.push({-(i + d[i]) , a[i]});
        
           while (pq.size() and i >= -pq.top().first)
               pq.pop();
           
           if (pq.size())
           {
               auto it = pq.top();
               it.second--;
               pq.pop();
               cur++;
              if (it.second) pq.push(it);
           }
       }
        while (pq.size())
        {
           while (pq.size() and i >= -pq.top().first)
             pq.pop();
            if (pq.size() == 0)
                continue;
            auto it = pq.top();
            pq.pop();
            cur++ , i++;
            it.second--;
            if (it.second > 0) pq.push(it);
        }
        return cur;
    }
};