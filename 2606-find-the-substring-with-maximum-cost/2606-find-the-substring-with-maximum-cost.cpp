class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        map < char , int > mp;
        for (int i = 0 ; i < chars.size(); i++)
            mp[chars[i]] = vals[i];
        
        for (char i = 'a'; i <= 'z'; i++)
        {
            if (mp.count(i))
                continue;
            mp[i] = i - 'a' + 1;
        }
        
        int sum = 0;
        int mx = 0;
        
        for (int i = 0 ; i < s.size(); i++)
        {
            int tmp = max(sum + mp[s[i]], mp[s[i]]);
            sum = tmp;
            mx = max(mx , sum);
        }
        
        return mx;
    }
};