class Solution 
{
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
    {
        unordered_map <string , int> mp;
        for (int i = 0 ; i < list1.size() ; i++)
            mp[list1[i]] = i;
        
         int mn = 1e9;
        
         for (int i = 0 ; i < list2.size() ; i++)
         {
             if (mp.count(list2[i]))
                 mn = min(mn , mp[list2[i]] + i);
         }
        
        vector < string > ret;
        for (int i = 0 ; i < list2.size() ; i++)
        {
             if (mp.count(list2[i]) and mp[list2[i]] + i == mn)
                 ret.push_back(list2[i]);
        }
        return ret;
    }
};