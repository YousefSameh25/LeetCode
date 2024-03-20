class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
       
        vector <int> premax (n) , sufmax(n);
        
        int mx = -1;
        for (int i = 0 ; i< n ; i++)
        {
            premax[i] = mx;
            mx = max(mx , height[i]);
        }
        
        mx = -1;
        for (int i = n - 1 ; i >= 0 ; i--)
        {
            sufmax[i] = mx;
            mx = max(mx , height[i]);
        }
        
        int ans = 0;
        for (int i = 0 ; i < n ; i++)
            ans += max(0 , min(premax[i] , sufmax[i]) - height[i]);
        
        return ans;
    }
};