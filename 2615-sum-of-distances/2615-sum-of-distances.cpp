class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        map < int , vector <int>> mp;
        for (int i = 0 ; i < nums.size(); i++)
            mp[nums[i]].push_back(i);
        
        map < int , vector < long long >> prefix;
        for (auto it : mp)
        {
            long long sum = 0;
            for (auto it2 : it.second)
            {
                sum += 1LL * it2;
                prefix[it.first].push_back(sum);
            }
        }
        
        vector < long long > ans (nums.size(), 0);
        for (int i = 0 ; i < nums.size() ; i++)
        {
            auto upper = upper_bound(mp[nums[i]].begin(), mp[nums[i]].end(), i) 
                - mp[nums[i]].begin();
            
            if (upper != mp[nums[i]].size())
            {
                ans[i] = prefix[nums[i]].back() - prefix[nums[i]][upper - 1] - 
                (i * (mp[nums[i]].size() - upper));
            }
            
            if (upper - 2 >= 0)
                ans[i] += -prefix[nums[i]][upper - 2] + (i * (upper - 1)); 
        }
        return ans;
    }
};