class Solution {
public:
    int minimumMoves(string s) {
        int ans = 0;
        for (int i = 0 ; i < s.size() ;)
        {
            if (s[i] != 'O')
                ans++ , i += 3;
            else 
                i++;
        }
        return ans;
    }
};