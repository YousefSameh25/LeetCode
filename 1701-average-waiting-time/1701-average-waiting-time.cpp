class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int curTime = 0;
        double waiting = 0;
        
        for (int i = 0 ; i < customers.size() ; i++)
        {
            waiting += customers[i][1];
            if (customers[i][0] < curTime)
            {
                waiting += curTime - customers[i][0];
                curTime += customers[i][1];
            }
            else
                curTime = customers[i][0] + customers[i][1];
        }
        return waiting / customers.size();
    }
};