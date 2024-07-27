class Solution {
public:


    vector < long long > dij(int source , vector < vector < long long >> &mat)
    {
       vector < long long > distance(26 , 1e18);
       distance[source]=0;

       priority_queue < pair < long long , int >> pq;
       pq.push({0, source});

       while(pq.size())
       {
            auto it = pq.top();
            pq.pop();
            int node  = it.second;
            long long totalCost = -it.first;

            if (totalCost > distance[node])
                continue;

            for (int i = 0 ; i < 26 ; i++)
            {
                if (mat[node][i] == 1e18 or node == i)
                    continue;
                if (distance[i] >= totalCost + mat[node][i])
                {
                    pq.push({-(totalCost + mat[node][i]), i});
                    distance[i] = totalCost + mat[node][i];
                }
            }
       }
       return distance;
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector < vector < long long >> arr (26, vector < long long> (26, 1e18));
        for(int i=0;i<26;i++)
        {
            fill(begin(arr[i]),end(arr[i]), 1e18);
            arr[i][i]=0;
        }
        //direct
        for (int i =0;i<original.size();i++)
        {
            int x=original[i]-'a';
            int y=changed[i]-'a';
            long long z=cost[i];
            arr[x][y]=min(arr[x][y],z); //noted
        }

        vector < vector < long long >> arr2 (26, vector < long long> (26, 1e18));

        for(int i=0; i < 26;i++)
            arr2[i] = dij(i, arr);

        long long ans = 0;
        for ( int i = 0 ; i < source.size(); i++)
        {
            if (arr2[source[i] - 'a'][target[i] - 'a'] == 1e18)
                return -1;
            ans += arr2[source[i] - 'a'][target[i] - 'a'];
        }



        return ans;
    }
};