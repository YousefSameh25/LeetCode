class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector < int > pre(words.size() + 1, 0);

        auto IsVowel = [](char ch) -> bool {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };

        for (int i = 0 ; i < words.size(); i++)
        {
            pre[i + 1] = IsVowel(words[i][0]) & IsVowel(words[i].back());
            pre[i + 1] += pre[i];
        }

        vector < int > ans;
        for (auto range : queries)
            ans.push_back(pre[range[1] + 1] - pre[range[0]]);
        return ans;
    }
};