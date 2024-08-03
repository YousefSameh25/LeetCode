class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
        int ans = 0;
        vector < pair < int , vector <int> >> v;
        for (auto &it : costs)
            v.push_back({abs(it[0] - it[1]), it});

        sort(v.rbegin(), v.rend());
        int cnt1 = v.size() / 2, cnt2 = v.size() / 2;
        for (int i = 0 ; i < v.size(); i++)
        {
            if (v[i].second[0] <= v[i].second[1])
            {
                if (cnt1)
                {
                    ans += v[i].second[0];
                    cnt1--;
                }
                else
                {
                    ans += v[i].second[1];
                    cnt2--;
                }
            }
            else
            {
                if (cnt2)
                {
                    ans += v[i].second[1];
                    cnt2--;
                }
                else
                {
                    ans += v[i].second[0];
                    cnt1--;
                }
            }
        }
        
        return ans;
    }
};