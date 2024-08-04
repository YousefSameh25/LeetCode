class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map < string, vector < string >> temp;
        for (int i = 0 ; i < strs.size(); i++)
        {
            string SortedStr = strs[i];
            sort(SortedStr.begin(), SortedStr.end());
            temp[SortedStr].emplace_back(strs[i]);
        }
        vector < vector < string > > ans;
        for (auto it : temp)
            ans.emplace_back(it.second);
        return ans;
    }
};