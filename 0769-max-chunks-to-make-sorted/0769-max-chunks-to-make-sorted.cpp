class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        vector < pair < int , int >> ranges;
        for (int i = 0 ; i < arr.size(); i++)
            ranges.push_back({i, arr[i]});

        int L = ranges[0].first, R = ranges[0].second, chunks = 1;
        for (int i = 1 ; i < ranges.size(); i++)
        {
            if (ranges[i].first > R)
            {
                L = ranges[i].first;
                R = ranges[i].second;
                chunks++;
            }
            else
            {
                R = max(R, ranges[i].second);
            }
        }
        return chunks;
    }
};