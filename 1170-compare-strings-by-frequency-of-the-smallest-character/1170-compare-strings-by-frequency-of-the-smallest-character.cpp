class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        
        vector <int > temp;
        for (int i = 0 ; i < words.size(); i++)
        {
            char mnChar = *min_element(words[i].begin(), words[i].end());
            int cnt = 0;
            for (char c : words[i])
                cnt += c == mnChar;
            
            temp.push_back(cnt);
        }
        
        sort(temp.begin(), temp.end());
        
        vector < int > ans;
        for (int i = 0 ; i < queries.size(); i++)
        {
            char mnChar = *min_element(queries[i].begin(), queries[i].end());
            int cnt = 0;
            for (char c : queries[i])
                cnt += c == mnChar;
            
            auto it = upper_bound(temp.begin(), temp.end(), cnt);
            
            ans.push_back(temp.end() - it);
        }
        return ans;
    }
};