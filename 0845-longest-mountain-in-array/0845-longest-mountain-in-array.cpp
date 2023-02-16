class Solution {
public:
    int longestMountain(vector<int>& arr) 
    {
        int n = arr.size() , mx = 0;
        vector <int> l(10000 + 10 , 0) , r(10000 + 10 , 0);
        for(int i  =1 ; i< n;i++)
        {
            if(arr[i] > arr[i-1])
                l[i] += l[i-1] + 1;
            else 
                l[i] = 0;
        }
        
        for(int i = n - 2 ; i >= 0 ; i--)
        {
            if(arr[i] > arr[i+1])
                r[i] += r[i+1] + 1;
            else 
                r[i] = 0;
        }
        
       for(int i = 0 ; i < n ;i++)
       {
          if(!l[i] or !r[i])
              continue;
           mx = max(mx , l[i] + r[i] +1);
       }
        return mx;
    }
};