class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0; 
        priority_queue <int> pq;
        pq.push(-prices[0]);
        
        for (int i = 1 ; i < prices.size(); i++)
        {
            int mn = -pq.top();
            pq.pop();
            if (mn < prices[i])
                ans += prices[i] - mn;
            pq.push(-prices[i]);
        }
        return ans;
    }
};