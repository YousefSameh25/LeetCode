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
            sum += mp[s[i]];
            mx = max(mx , sum);
            if (sum < mp[s[i]])
                sum = mp[s[i]];
            mx = max(mx , sum);
        }
        
        return mx;
    }
};