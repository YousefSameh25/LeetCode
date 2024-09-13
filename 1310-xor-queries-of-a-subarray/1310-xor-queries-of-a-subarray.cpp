class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), Xor = 0;
        for (int i = 0 ; i < n ; i++)
        {
            Xor ^= arr[i];
            arr[i] = Xor;  
        }
        vector < int > ans;
        for (auto &r : queries)
        {
            int l = r[0] > 0 ? arr[r[0] - 1] : 0;
            ans.push_back(arr[r[1]] ^ l);
        }
        return ans;
    }
};