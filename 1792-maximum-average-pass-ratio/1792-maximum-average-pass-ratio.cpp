class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) 
    {
        priority_queue < pair < double , vector < int > > > pq;
        for (auto &it : classes)
        {
            pq.push({(1.0 * (it[0] + 1) / (it[1] + 1) - (1.0 * it[0] / it[1])), it});
        }
        while(extraStudents--)
        {
            auto top = pq.top();
            pq.pop();
            top.second[0]++, top.second[1]++;
            top.first = (1.0 * (top.second[0] + 1) / (top.second[1] + 1)) 
                                    - (1.0 * top.second[0] / top.second[1]);
            pq.push(top);
        }

        double ans = 0;
        while(pq.size())
        {
            auto top = pq.top();
            pq.pop();
            ans += 1.0 * top.second[0] / top.second[1];
        }
        return ans / classes.size();
    }
};