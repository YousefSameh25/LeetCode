class Solution {
public:
    int distMoney(int money, int n) 
    {
        if (money < n)
            return -1;
        vector < int > v (n , 1);
        money -= n;
        for (int i = 0 ; i < n ; i++)
        {
            v[i] += min(7 , money);
            money -= min (7 , money);
        }
        if (money)
            v[n - 1] += money;
        
        int e = 0 , f = 0 , o = 0;
        for (int i = 0 ; i < n ; i++)
        {
            if (v[i] == 8)  e++;
            else if (v[i] == 4) f++;
            else o++;
        }
        f -= min(f , o);
        e -= f;
        return e;
    }
};