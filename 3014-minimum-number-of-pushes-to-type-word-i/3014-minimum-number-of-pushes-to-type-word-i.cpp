class Solution {
public:
    int minimumPushes(string word) {
        int cost = 0, n = word.size(), i = 1;
        while (n)
        {
            if (n >= 8)
            {
                n -= 8;
                cost += 8 * i;
            } 
            else
            {
                cost += n * i; 
                n = 0;
            }
            i++;
        }
        return cost;
    }
};