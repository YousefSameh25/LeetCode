class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue < long long > pq;
        pq.push(-1);
        unordered_set < long long > vis;
        vis.insert(1);
        int child[3] = {2, 3, 5};
        for (int i = 1; i <= n ; i++)
        {
            auto mn = -pq.top();
            if (i == n)
                return mn;
            pq.pop();

            for (int i = 0; i < 3 ; i++)
            {
                if (vis.count(mn * child[i]))
                    continue;
                vis.insert(mn * child[i]);
                pq.push(-mn * child[i]);
            }
        }

        return -pq.top();
    }
};