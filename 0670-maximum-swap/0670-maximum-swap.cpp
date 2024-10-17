class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int mx = 0;
        for (int i = 0 ; i < s.size(); i++)
        {
            for (int j = i ; j < s.size() ; j++)
            {
                swap(s[i], s[j]);
                mx = max(mx , stoi(s));
                swap(s[i], s[j]);
            }
        }
        return mx;
    }
};