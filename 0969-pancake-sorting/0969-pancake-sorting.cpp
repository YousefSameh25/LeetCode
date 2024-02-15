class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) 
    {
        vector <int> ans;
        for (int i = arr.size() - 1 ; i >= 0 ; i--)
        {
             if (arr[i] != i + 1)
             {
                 // Find it's position
                 int idx;
                 for (int j = 0 ; j < i ; j++)
                 {
                     if (arr[j] == i + 1)
                     {
                         idx = j; 
                         break;
                     }
                 }
                 reverse (arr.begin() , arr.begin() + idx + 1);
                 ans.push_back(idx + 1);
                 reverse (arr.begin() , arr.begin() + i + 1);
                 ans.push_back(i + 1); 
             }
        }
        return ans;
    }
};