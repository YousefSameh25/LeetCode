class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        priority_queue < pair < int , int > > pq;
        for (int i = 0 ; i < plantTime.size() ;i++)
            pq.push({growTime[i] , plantTime[i]});
        int d = 0 , mx = 0;
        while(pq.size())
        {
            auto t = pq.top();
            pq.pop();
            mx = max (mx , t.first + t.second + d);
            d += t.second;
        }
        return mx;
    }
};