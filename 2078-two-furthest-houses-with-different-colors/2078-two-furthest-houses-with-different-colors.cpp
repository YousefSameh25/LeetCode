class Solution {
public:
    int maxDistance(vector<int>& colors) 
    {
        int e = colors.size() - 1 , s = 0; 
        
        // option (1)
        while (colors.front() == colors[e])
            e--;
        
        // option (2)
        while (colors.back() == colors [s])
            s++;
    
        return max (e , (int) colors.size() - 1 - s);
    }
};