class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for (int i = 0; i < chalk.size(); i++)
            sum += 1LL * chalk[i];

        k -= (k / sum) * sum;

        for (int i = 0 ; i < chalk.size(); i++)
        {
            if (k < chalk[i])
                return i;
            k -= chalk[i];
        }
        return 404;
    }
};