class Solution {
public:
    int minimumCardPickup(vector<int>& cards) 
    {
        map < int , int > position;
        int mn = INT_MAX;
        for (int i = 0 ; i < cards.size(); i++)
        {
            if (!position.count(cards[i])) 
            {
                position[cards[i]] = i;
                continue;
            }
            mn = min(mn, i - position[cards[i]] + 1);
            position[cards[i]] = i;
        }
        return (mn == INT_MAX)? -1 : mn;
    }
};