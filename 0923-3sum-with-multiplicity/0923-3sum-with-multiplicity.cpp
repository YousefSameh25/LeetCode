class Solution {
public:
    const int MOD = 1e9 + 7;
    int Add(int a, int b)
    {
        a %= MOD;
        b %= MOD;
        return (a + b) % MOD;
    }
    
    int threeSumMulti(vector<int>& arr, int target) {
        
        int ans = 0;
        map  <int , int> mp;
        for (int i = 0 ; i < arr.size() ; i++)
        {
            for (int j = i + 1 ; j < arr.size(); j++)
            {
                ans = Add(ans, mp[target - (arr[i] + arr[j])]);
            }
            mp[arr[i]]++;
        }
        
        return ans;
    }
};