class Solution {
public:
    int maxArea(vector <int> & height) 
    {
        int l = 0 , r = height.size() - 1 , mx = 0;
        while (l < r)
        {
            int vol = min(height[l] , height[r]) * (r - l) ;
            mx = max(mx , vol);
            if (height[l] < height[r])
                l++;
            else if (height[l] > height[r])
                r--;
            else 
                l++;
        }
        return mx;
    }
};