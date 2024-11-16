class Solution {
public:
    vector<int> resultsArray(vector<int>& arr, int k) {

        vector < int > ans(arr.size() - k + 1);
        for (int i = 0 ; i + k - 1 < arr.size(); i++)
        {
            bool tmp = 1;
            for (int j = i ; j + 1 < i + k ;j++)
            {
                tmp &= arr[j] == arr[j + 1] - 1;
            }
            if (tmp)
            {
                ans[i] = arr[i + k - 1];
            }
            else
            {
                ans[i] = -1;
            }
        }
        return ans;
    }
};