class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) 
    {
        map <int , int> mp;
        for (auto &it : logs)
            mp[it[0]]++ , mp [it[1]]--;
        int sum = 0 , mx = 0 , ans;
        for (auto &it : mp)
        {
            sum += it.second;
            it.second = sum;
            if (sum > mx)
                mx = sum , ans = it.first;
        }
        return ans;
    }
};