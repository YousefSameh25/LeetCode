class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        int ans = 0;
        priority_queue < long > pq;
        for (auto it : nums)
        {
            pq.push(-it);
        }
        
        while(pq.size() and -pq.top() < k)
        {
            long mn1 = -pq.top();
            pq.pop();
            long mn2 = -pq.top();
            pq.pop();
            pq.push(-(mn1 * 2 + mn2));
            ans++;
        }
        return ans;
    }
};