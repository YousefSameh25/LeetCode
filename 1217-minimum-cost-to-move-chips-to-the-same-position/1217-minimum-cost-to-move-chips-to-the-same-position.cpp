class Solution {
public:
    int minCostToMoveChips(vector<int> & position)
    {
        int e = 0 , o = 0;
        map < int , int > mp;
        for (auto it : position)
        {
            (it & 1) ? o++ : e++;
            mp[it] ++;
        }
        int n = position.size() , mn = 1e9;
        for (auto it : position)
        {
            int steps = 0 , tmpo  = o , tmpe = e;
            (it & 1)? tmpo -= mp[it] :tmpe -= mp[it];
            (it & 1)? steps = tmpe : steps = tmpo;
            mn = min(mn , steps);
        }
        return mn;
    }
};