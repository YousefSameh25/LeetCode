public class Solution {
    public IList<int> PartitionLabels(string s) {
        int[] l = new int[26];
        int[] r = new int[26];

        for (int i = 0; i < 26; i++)
            l[i] = r[i] = -1;

        for (int i = 0; i < s.Length; i++)
        {
            if (l[s[i] - 'a'] == -1)
                l[s[i] - 'a'] = i;
        }

        for (int i = s.Length - 1; i >= 0; i--)
        {
            if (r[s[i] - 'a'] == -1)
                r[s[i] - 'a'] = i;
        }

        IList<int> ans = new List<int>();

        int x = l[s[0] - 'a'], y = r[s[0] - 'a'];

        for (int i = 1; i < s.Length; i++)
        {
            if (x <= l[s[i] - 'a'] && y >= r[s[i] - 'a'])
                continue;
            if (l[s[i] - 'a'] > y)
            {
                ans.Add(y - x + 1);
                x = l[s[i] - 'a'];
                y = r[s[i] - 'a'];
            }
            else if (l[s[i] - 'a'] < y && r[s[i] - 'a'] > y)
                y = r[s[i] - 'a'];
        }
        ans.Add(y - x + 1);
        return ans;
    }
}