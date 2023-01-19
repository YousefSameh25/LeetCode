class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin() , s.end());
        sort(g.begin() , g.end());
        int ans = 0;
        for (int i = 0 , j = 0 ; i < g.size() && j < s.size() ; j++)
        {
            if (s[j] >= g[i])
            {
                i++;
                ans++;
            }
        }
        return ans;
    }
};