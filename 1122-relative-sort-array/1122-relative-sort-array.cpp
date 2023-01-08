class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector <int> f (1010 , 0);
        for (auto it : arr1)
            f[it]++;
        
      vector <int> ret;
      for (auto it : arr2)
      {
          int r = f[it];
          while(r--)
          {
             ret.push_back(it);
          }
          f[it] = 0;
      }
        for (int i = 0 ; i <= 1009 ; i++)
        {
          int r = f[i];
          while(r--)
          {
             ret.push_back(i);
          }
        }
        return ret;
    }
};