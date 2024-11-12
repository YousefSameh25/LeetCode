class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) 
    {
        sort(items.begin(), items.end());
        for (int i = 1; i < items.size(); i++)
            items[i][1] = max(items[i][1], items[i - 1][1]);

        for (int i = 0 ; i < queries.size(); i++)
        {
            vector < int > temp = {queries[i], 1000000000};
            auto it = upper_bound(items.begin(), items.end(), temp) - items.begin();
            it--;
            queries[i] = it >= 0 ? items[it][1] : 0;
        }
        return queries;
    }
};