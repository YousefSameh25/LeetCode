class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue < pair < int, int>> pq;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            pq.push({-nums[i], -i});
        }

        while(k--)
        {
            auto top = pq.top();
            pq.pop();
            top.first *= multiplier;
            pq.push(top);
        }

        while(pq.size())
        {
            auto top = pq.top();
            pq.pop();
            nums[-top.second] = -top.first;
        }
        return nums;
    }
};