class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) 
    {
        double mx = 0;
        for (auto &f : points)
        {
            for (auto &s : points)
            {
                for (auto &t : points)
                {
                    double a = hypot (f[0] - s[0] , f[1] - s[1]);
                    double b = hypot (f[0] - t[0] , f[1] - t[1]);
                    double c = hypot (s[0] - t[0] , s[1] - t[1]);
                    double s = (a + b + c) / 2; 
                    a = s - a , b = s - b , c = s - c;
                    mx = max(mx , sqrt(s * a * b * c));
                }
            }
        }
        return mx;
    }
};