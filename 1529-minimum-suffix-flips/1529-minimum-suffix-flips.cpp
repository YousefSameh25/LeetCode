class Solution {
public:
    int minFlips(string target) {
        int f = 0;
        for (int i = 0 ; i < target.size() ; i++)
        {
            char cur = (f & 1)? '1' : '0';
            if (cur == target[i])
                continue;
            f++;
        }
        return f;
    }
};