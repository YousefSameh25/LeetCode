class Solution {
public:
    int candy(vector<int>& ratings)
    {
        
        if (ratings.size() == 1)
            return 1;
        
        vector < pair < int , int >> v;
        for (int i = 0 ; i < ratings.size() ; i++)
        {
            v.push_back({ratings[i] , i});
        }
        sort (v.begin() , v.end());
        vector < int > have (ratings.size() , 0);
        
        for (auto it : v)
        {
            int r = it.first , i = it.second;
            if (i == v.size() - 1)
            {
                if (have[i - 1] == 0 or r == ratings[i - 1])
                    have [i] = 1;
                else 
                    have [i] = have[i - 1] + 1;
            }
            else if (i == 0)
            {
                if (have[i + 1] == 0  or r == ratings[i + 1])
                    have [i] = 1;
                else 
                    have [i] = have[i + 1] + 1;
            }
            else
            {
               if (r == ratings[i - 1] and r == ratings[i + 1])
                   have[i] = 1;
               else if (have[i - 1] == 0 and have[i + 1] == 0)
                    have[i] = 1;
               else if (have[i - 1] == 0)
               {
                   if (r == ratings[i + 1])
                       have[i] = 1;
                   else 
                       have[i] = have[i + 1] + 1;
               }
                else if (have[i + 1] == 0)
               {
                   if (r == ratings[i - 1])
                       have[i] = 1;
                   else 
                       have[i] = have[i - 1] + 1;
               }
                else 
                {
                    if (r > ratings[i - 1] and r > ratings[i + 1])
                        have[i] = max(have[i - 1] , have[i + 1]) + 1;
                    else if (r  ==  ratings[i - 1])
                        have[i] = have[i + 1] + 1;
                    else if (r == ratings[i + 1])
                        have[i] = have[i - 1] + 1;
                }
                
            }
        }
        return accumulate(have.begin() , have.end() , 0);
    }
};