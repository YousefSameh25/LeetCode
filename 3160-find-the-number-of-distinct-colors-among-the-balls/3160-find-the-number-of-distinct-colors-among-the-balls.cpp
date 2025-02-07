class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) 
    {
        vector < int > ans;
        map < int , int > ColorFrq, BallColor;
        for (auto it : queries)
        {
            // Same
            if (BallColor.count(it[0]) and BallColor[it[0]] == it[1])
            {
                ans.push_back(ColorFrq.size());
                continue;
            }

            // Decrease the frq of old ball color
            if (BallColor.count(it[0]))
                ColorFrq[BallColor[it[0]]]--;
            
            if (BallColor.count(it[0]) and !ColorFrq[BallColor[it[0]]])
                ColorFrq.erase(BallColor[it[0]]);

            // Increase the frq of new ball color
            ColorFrq[it[1]]++;
            BallColor[it[0]] = it[1];
            ans.push_back(ColorFrq.size());
        }
        return ans;
    }
};