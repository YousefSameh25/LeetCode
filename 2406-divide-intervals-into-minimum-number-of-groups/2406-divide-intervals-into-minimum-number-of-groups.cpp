class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for (int i = 0 ; i < n ; i++)
            swap(intervals[i][0], intervals[i][1]);

        sort(intervals.begin(), intervals.end());

        for (int i = 0 ; i < n ; i++)
            swap(intervals[i][0], intervals[i][1]);

        int g = 0;
        set < pair < int , int >> st;
        for(int i = 0 ; i < n ; i++)
        {
            if (st.empty())
            {
                g++;
                st.insert({intervals[i][1], g});
                continue;
            }
            auto end = st.upper_bound({intervals[i][0], -1e9});
            while(end == st.end() or (end -> first >= intervals[i][0] and end != st.begin()))
                end--;
            
            if (end -> first < intervals[i][0])
            {
                int tempG = end -> second;
                st.erase(end);
                st.insert({intervals[i][1], tempG});
            }
            else
            {
                g++;
                st.insert({intervals[i][1], g});
            }
        }
        return g;
    }
};