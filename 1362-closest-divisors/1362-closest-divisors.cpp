class Solution {
public:
    vector<int> closestDivisors(int num) {
        int mn = 1e9 , x , y;
        num++;
        for (int i = 1 ; i * i <= num ; i++)
        {
            if (num % i == 0)
            {
                int d = num / i - i;
                if (mn > d)
                    mn = d, x = i , y = num / i;
            }
        }
        num++;
         for (int i = 1 ; i * i <= num ; i++)
        {
            if (num % i == 0)
            {
                int d = num / i - i;
                if (mn > d)
                    mn = d, x = i , y = num / i;
            }
        }
        return {x,y};
    }
};