class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int mxCost = 0;
        vector <int> CostsFreq(1e5 + 1 , 0);
        for (auto it: costs)
            CostsFreq[it]++ , mxCost = max(mxCost, it);
        
        int ans = 0;
        for (int i = 1 ; i <= mxCost; i++)
        {
            int CanBeBought = min(coins / i, CostsFreq[i]);
            ans += CanBeBought;
            coins -= CanBeBought * i;
        }
        return ans;
    }
};