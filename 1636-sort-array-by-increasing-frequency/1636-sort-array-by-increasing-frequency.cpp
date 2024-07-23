class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector < int > frq(201, 0);
        for (auto it : nums)
            frq[it + 100]++;

        vector < pair < int , int > > res;
        for(int i = 0 ; i <= 200; i++)
            res.push_back({frq[i], i});
        
        sort(res.begin(), res.end(), [&](pair<int , int> a, pair < int , int > b) {
            if(a.first == b.first)
                return a.second > b.second;
            return b.first > a.first;
        });

        vector < int > ans;

        for(auto &it : res)
        {
            while(it.first--)
                ans.push_back(it.second - 100);
        }

        return ans;
    }
};