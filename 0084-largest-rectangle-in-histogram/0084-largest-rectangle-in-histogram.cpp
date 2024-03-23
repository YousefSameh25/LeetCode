class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        vector < int > PreMinIdx(n) , SuffMinIdx(n);
        
        stack < pair <int , int> > st;
        
        for (int i = 0 ; i < n ; i++)
        {
            while(st.size() and st.top().first >= heights[i]) st.pop();
            PreMinIdx[i] = st.size()? st.top().second : -1;
            st.push({heights[i] , i});
        }
        
        while(st.size()) st.pop();
        
        for (int i = n - 1 ; i >= 0 ; i--)
        {
            while(st.size() and st.top().first >= heights[i]) st.pop();
            SuffMinIdx[i] = st.size()? st.top().second : n;
            st.push({heights[i] , i});
        }
        
        int maxArea = 0;
        for ( int i = 0 ; i < n ; i++)
            maxArea = max(maxArea , (SuffMinIdx[i] - PreMinIdx[i] - 1) * heights[i]);
        
        return maxArea;  
    }
};