class Solution {
public:
    bool primeSubOperation(vector<int>& nums) 
    {
        vector < bool > primes(1000 + 1, 1);
        for ( int i = 2; i <= 1000; i++)
        {
            if (!primes[i])
                continue;
            for (int j = i + i; j <= 1000; j += i)
            {
                primes[j] = 0;
            }
        }

        vector < int > pri;
        for (int i = 2; i <= 1000 ;i++)
        {
            if (primes[i])
                pri.push_back(i);       
        }

        for (int i = 0; i < nums.size(); i++)
        {
            auto it = upper_bound(pri.begin(), pri.end(), nums[i] - 1 - (i? nums[i - 1] : 0)) - pri.begin();
            it--;
            if (it >= 0 and it < pri.size())
                nums[i] -= pri[it];
        }
        
        for (int i = 1 ; i < nums.size(); i++)
        {
            if (nums[i] <= nums[i - 1])
                return 0;
        }
        return 1;
    }
};