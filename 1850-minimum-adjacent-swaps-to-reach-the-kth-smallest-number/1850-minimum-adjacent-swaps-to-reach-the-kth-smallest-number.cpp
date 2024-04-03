class Solution {
public:
    int getMinSwaps(string num, int k) {
        
        string newString = num;
            
        while(k--)
            next_permutation(newString.begin() , newString.end());
        
        int ans = 0;
        
       for (int i = 0 ; i < num.size() ; i++)
       {
           if (num[i] != newString[i])
           {
               int RI = -1;
               for (int j = i + 1; j < num.size(); j++)
               {
                   if (num[i] == newString[j])
                   {
                       RI = j;
                       break;
                   }
               }
               for (int j = RI; j > i; j--)
                   swap(newString[j], newString[j - 1]), ans++;
           }
          
       }
        
       return ans;
    }
};