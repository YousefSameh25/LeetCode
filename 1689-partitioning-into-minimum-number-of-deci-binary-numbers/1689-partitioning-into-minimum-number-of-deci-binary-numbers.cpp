class Solution {
public:
    int minPartitions(string n) {
        char mx = ' ';
        for (char c : n)
        {
            if (mx == ' ')
                mx = c;
            else 
                mx = max(mx , c);
        }
        return mx - '0';
    }
};