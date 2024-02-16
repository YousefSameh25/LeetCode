class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n = arr.size();
        vector <int> pre(n);
        pre[0] = arr[0];
        for (int i = 1 ; i < n ; i++)
        {
            pre[i] = arr[i];
            pre[i] ^= pre[i - 1];
        }
        
        vector <int> ans;
        for (auto it : queries)
        {
            if (it[0] - 1 >= 0)
                ans.push_back(pre[it[1]] ^ pre[it[0] - 1]);
            else 
                ans.push_back(pre[it[1]]);
        }
        
        return ans;
    }
};