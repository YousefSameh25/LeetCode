class Solution {
public:
    int maxDistance(vector<int>& colors) 
    {
        int n = colors.size() , mx = 0; 
        for (int i = 0 ; i < n  ; i++)
        {
            int cur = colors[i];
            for (int j = 0 ; j < n ; j++)
            {
                if (colors[i] != colors[j])
                    mx = max (mx , abs (j - i));
            }
        }
        return mx;
    }
};