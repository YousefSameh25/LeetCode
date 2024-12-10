class Solution {
public:
    int maximumLength(string s) {
        int mat[26][51];
        memset (mat, 0, sizeof(mat));
        int mx = 0;
        for (int i = 0 ; i < s.size(); )
        {
            char c = s[i];
            int len = 1, j = i + 1;
            while(j < s.size() and s[j] == c)
                len++, j++;
            i = j;
            for (int k = 1 ; k <= len; k++)
            {
                mat[c - 'a'][k] += len - (k - 1);
                if (mat[c - 'a'][k] > 2)
                    mx = max(mx , k);
            }
        }
        return mx == 0 ? -1 : mx;
    }
};