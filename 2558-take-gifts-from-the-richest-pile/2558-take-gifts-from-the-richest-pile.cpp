class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue < int > pq;
        for (auto it : gifts)
        {
            pq.push(it);
        }
        
        while(k--)
        {
            auto it = pq.top();
            pq.pop();
            pq.push(sqrt(it));
        }
        long long sum = 0;
        while(pq.size())
        {
            auto it = pq.top();
            sum += 1LL * it;
            pq.pop();
        }
        return sum;
    }
};