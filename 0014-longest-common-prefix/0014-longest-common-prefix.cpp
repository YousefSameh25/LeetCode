class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int m = 1e9;
        for (auto &str : strs)
            m = min(m, (int) str.size());

        string ans;
        for (int j = 0; j < m; j++)
        {
            for (int i = 1 ; i < strs.size(); i++)
            {
                if (strs[i][j] != strs[i - 1][j])
                    return ans;
            }
            ans.push_back(strs.back()[j]);
        }
        return ans;
    }
};