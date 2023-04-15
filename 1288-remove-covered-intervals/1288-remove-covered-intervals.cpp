class Solution {
public:
    bool in_range (int a , int b , int c , int d)
    {
        return (a >= c and a <= d and b >= c and b <= d);
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin() , intervals.end());
        
        
        priority_queue < vector <int> > pq;
        
        for (auto it : intervals)
        {
            it[0] *= -1;
            pq.push(it);
        }
        
        intervals.clear();
        
        while (pq.size())
        {
            intervals.push_back(pq.top());
            intervals.back()[0] *= -1;
            pq.pop();   
        }
        
        
        int ans = 1;
        vector <int> cur = intervals[0];
        for (int i = 1 ; i < intervals.size() ; i++)
        {
            if (not in_range(intervals[i][0] , intervals[i][1] - 1 , cur[0] , cur[1] - 1))
            {
                ans++;
                cur = intervals[i];
            }
        }
        return ans;
    } 
};