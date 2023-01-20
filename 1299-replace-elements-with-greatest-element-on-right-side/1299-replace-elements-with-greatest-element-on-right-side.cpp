class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector < int > v(arr.size());
        int mx  = -1; 
        for (int i = arr.size () - 1 ; i >= 0 ;i--)
        {
            v[i] = mx;
            mx  = max(mx , arr[i]);
        }
        return v;
    }
};