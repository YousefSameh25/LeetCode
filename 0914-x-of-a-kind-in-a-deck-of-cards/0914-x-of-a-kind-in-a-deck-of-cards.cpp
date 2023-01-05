class Solution {
public:
    bool hasGroupsSizeX(vector<int> & deck) {
        int frq[10000 + 10] = {} , dis = 0;
        for (auto it : deck)
        {
            dis += (frq[it] == 0);
            frq[it]++;
        }
        
        int frq2 [10000 + 10] = {};
        
        for (int i = 0 ; i <= 1e4 + 9 ; i++)
        {
            if (!frq[i])
                continue;
           
            for (int j = 1 ; j * j <= frq[i] ; j++)
            {
                if (frq[i] % j == 0)
                {
                    frq2[j]++;
                    if (j != frq[i] / j)
                        frq2[frq[i] / j] ++;
                }
            }
        }
        
        for (int i = 2 ; i <= 1e4 + 9 ; i++)
        {
             if (!frq2[i])
                continue;
            if (frq2[i] == dis)
                return 1;
        }   
        return 0;
    }
};