class Solution 
{
public:
    vector <int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        vector < pair < int , int > > v;
        for (auto &row : mat)
        {
            int l = 0 , r = row.size() - 1 , ans = 0;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (row[mid] == 1)
                    l = mid + 1 , ans = mid + 1;
                else 
                    r = mid - 1;
            }
            v.push_back({ans , v.size()});
        }
        sort(v.begin() , v.end());
        while(v.size() > k)
            v.pop_back();
        vector < int > ans;
        for (auto &it : v)
            ans.push_back(it.second);
        return ans;      
    }
};