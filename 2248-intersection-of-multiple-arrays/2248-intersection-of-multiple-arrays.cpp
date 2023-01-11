class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) 
    {
        vector < int > ans , f(1001 , 0);
        for (int i= 0 ; i < nums.size() ; i++)
        {
            set < pair < int , int > > s;
            for (int j = 0 ; j < nums[i].size() ; j++)
            {
                if (s.count({i , nums[i][j]}))
                    continue;
                f[nums[i][j]] ++;
                s.insert({i , nums[i][j]});
            }
        }
        for (int i = 1 ; i <= 1000 ; i++)
        {
            if (f[i] == nums.size())
                ans.push_back(i);
        }
        return ans;
    }
};