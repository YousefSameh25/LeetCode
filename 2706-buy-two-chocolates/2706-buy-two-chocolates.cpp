class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        priority_queue < int > pq;
        for (int &pri : prices)
        {
            pq.push(pri);
            if (pq.size() > 2)
                pq.pop();
        }
        int sum = 0;
        while(pq.size()) sum += pq.top(), pq.pop();
        return sum <= money ? money - sum : money;
    }
};