class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort (piles.begin() , piles.end());
        int ans = 0 , j = 0;
        for (int i = piles.size() - 2 ; i >= j ; i -= 2)
        {
            ans += piles[i];
            j++;
        }
        return ans;
    }
};