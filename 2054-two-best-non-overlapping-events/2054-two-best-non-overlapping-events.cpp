class Solution 
{
public:
    int maxTwoEvents(vector<vector<int>>& events) 
    {
        sort(events.begin(), events.end());  
        map < int , int > mp;
        int ans = 0;
        for (int i = events.size() - 1 ;  i >= 0 ; i--)
        {
            ans = max(ans, events[i][2]);
            mp[events[i][0]] = ans;
        }

        long long ret = 0;
        for (int i = 0 ; i < events.size(); i++)
        {
            long long sum = events[i][2];
            auto it = mp.lower_bound(events[i][1] + 1);
            if (it != mp.end())
                sum += 1LL * it -> second;
            ret = max(ret, sum);
        }
        return ret;
    }
};