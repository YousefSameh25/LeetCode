class Solution {
    public:
    vector < int > primes;
    void GeneratePrimes()
    {
        int n = 1e6 + 1;
        vector<bool> isPrime (1e6 + 1, 1);
        for (int i = 2; i * i < n; i++)
        {
            if (!isPrime[i])
                continue;
            for(int j = i + i; j < n; j += i)
            {
                isPrime[j] = 0;
            }
        }
        for (int i = 2; i < n ; i++)
            if (isPrime[i])
                primes.push_back(i);
    }
    vector<int> closestPrimes(int left, int right) {
        GeneratePrimes();

        int mn = 1e9;
        vector < int > ans = {-1, -1};
        for (int i = 0; i + 1 < primes.size(); i++)
        {
            if (left <= primes[i] and primes[i + 1] <= right)
            {
                if (primes[i + 1] - primes[i] < mn)
                {
                    mn = primes[i + 1] - primes[i];
                    ans = {primes[i], primes[i + 1]};
                }
            }
        }
        
        return ans;
    }
};