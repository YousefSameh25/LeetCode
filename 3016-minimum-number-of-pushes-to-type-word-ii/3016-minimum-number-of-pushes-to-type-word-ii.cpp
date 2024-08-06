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

        int iteration = 1, ans = 0;
        while(pq.size())
        {
            auto it = pq.top();
            pq.pop();
            ans += it * ((iteration + 7) / 8);
            iteration++;
        }
        return ans;
    }
};