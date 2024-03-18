class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin() , points.end());
        int mnShoots = 1 , x = points[0][0] ,  y = points[0][1];
        for (int i = 1 ; i < points.size() ; i++)
        {
            if (points[i][0] >= x and points[i][0] <= y)
            {
                x = max(x , points[i][0]);
                y = min(y , points[i][1]);
                continue;
            }
            mnShoots++;
            x = points[i][0];
            y = points[i][1];
        }
        return mnShoots;
    }
};