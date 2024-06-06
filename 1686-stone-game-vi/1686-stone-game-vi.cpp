class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) 
    {
        int n = aliceValues.size();
        
        vector <vector <int>> v1, v2;
        for (int i = 0 ; i < n ; i++)
        {
                v1.push_back({bobValues[i] + aliceValues[i] , aliceValues[i] , i});
                v2.push_back({bobValues[i] + aliceValues[i] , bobValues[i] , i});  
        }
        
        sort (v1.begin(), v1.end());
        sort (v2.begin(), v2.end());
        
        map <int , bool> taken;

        int sumA = 0 , sumB = 0;
        for (int i = 0 ; i < n ; i++)
        {
            if(i & 1)
            {
                while(taken.count(v2.back()[2]))
                    v2.pop_back();
                
                sumB += v2.back()[1];
                taken[v2.back()[2]] = 1;
            }
            else 
            {
                while(taken.count(v1.back()[2]))
                    v1.pop_back();
                
                sumA += v1.back()[1];
                taken[v1.back()[2]] = 1;
            }
        }
        
        if(sumB == sumA) return 0;
        else if (sumA > sumB) return 1;
        return -1;
    }
};