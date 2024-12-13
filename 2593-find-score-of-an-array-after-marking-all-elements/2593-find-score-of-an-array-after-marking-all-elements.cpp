class Solution {
public:
    long long findScore(vector<int>& nums) 
    {
        long long ans = 0;
        priority_queue < pair < int , int > > pq;
        for (int i = 0 ; i < nums.size(); i++)
        {
            pq.push({-nums[i], -(i + 1)});
        }

        vector < bool > vis(nums.size() + 2, 0);
        while(pq.size())
        {
            while(pq.size() and vis[-pq.top().second])
                pq.pop();

            if (pq.empty())
                break;
            
            auto it = pq.top();
            pq.pop();
            ans += -it.first;
            vis[-it.second] = 1;
            vis[-it.second - 1] = 1, vis[-it.second + 1] = 1;
        }
        return ans;
    }
};