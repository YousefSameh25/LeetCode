class Solution {
public:
    int minTimeToType(string word) 
    {
        int ans  = word.size();
        char prv = 'a';
        for (char c : word)
        {
            int op1 = abs ((prv - 'a') - ( c - 'a'));
            int op2 = 26 - op1;
            ans += min (op1 , op2);
            prv = c;
        }
        return ans;
    }
};