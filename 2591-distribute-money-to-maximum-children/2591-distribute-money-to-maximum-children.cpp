class Solution {
public:
    int distMoney(int money, int n) 
    {
        if (money < n)
            return -1;
        vector < int > v (n , 0);
        for (int i = 0 ; i < n ; i++)
        {
            if (money)
                v[i] = 1 , money--;
        }
        
        for (int i = 0 ; i < n ; i++)
        {
            if (money >= 7)
                v[i] += 7 , money -= 7;
            else
                v[i] += money , money = 0;
        }
        if (money)
            v[n - 1] += money;
        
        int e = 0 , f = 0 , o = 0;
        for (int i = 0 ; i < n ; i++)
        {
            if (v[i] == 8)
                e++;
            else if (v[i] == 4)
                f++;
            else 
                o++;
        }
        f -= min(f , o);
        e -= f;
        return e;
    }
};