class Solution {
public:
    int fillCups(vector<int>& amount) 
    {
        priority_queue <int> pq;
        for (auto it: amount)
        {
            if (it)
                pq.push(it);
        }
        int ans = 0;
        while(pq.size())
        {
            int t1 = pq.top();
            pq.pop();
            if (pq.size())
            {
                int t2 = pq.top();
                pq.pop();
                ans++;
                t1--, t2--;
                if (t1) pq.push(t1);
                if (t2) pq.push(t2);
            }
            else 
            {
                ans += t1;
            }
        }
        return ans;        
    }
};