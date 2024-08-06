class Solution {
public:
    int minimumPushes(string word) {
        vector < int > frq(26 , 0);
        for (auto &it : word)
            frq[it - 'a']++;
        priority_queue < int > pq;
        for (int i = 0 ; i < 26 ; i++)
            if (frq[i])
                pq.push(frq[i]);
        
        vector < int > available (5, 8);
        available[4] = 2;

        int cost = 1, ans = 0;
        while(pq.size())
        {
            auto it = pq.top();
            pq.pop();
            ans += it * cost;
            available[cost]--;
            if (!available[cost])
                cost++;
        }
        return ans;
    }
};