class Solution 
{
public:
    vector<string> simplifiedFractions(int n) 
    {
        vector < string > ret;
       for (int i = 1 ; i < n ; i++)
       {
           
           for (int j = 2 ; j <= n ; j++)
           {
               if (i >= j)
                   continue;
               if (__gcd(i , j) == 1)
               {
                   string tmp = to_string(i)+ "/" + to_string(j);
                   ret.push_back(tmp);
               }
           }
       }
        return ret;
    }
};