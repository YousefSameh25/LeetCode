class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //              value, index, list# 
        priority_queue < vector < int > > mn;
        priority_queue < int > mx;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            mn.push({-nums[i][0], 0, i});
            mx.push(nums[i][0]);
        }

        int diff = 1e9;
        vector < int > ans;

        while(mn.size())
        {
            auto it = mn.top();
            auto it2 = mx.top();
            mn.pop();
            if (it2 + it[0] < diff)
            {
                diff = it2 + it[0];
                ans = {-it[0], it2};
            }
            if (it[1] + 1 >= nums[it[2]].size())
                break;
            mn.push({-nums[it[2]][it[1] + 1], it[1] + 1, it[2]});
            mx.push(nums[it[2]][it[1] + 1]);
        }
        return ans;
    }
};