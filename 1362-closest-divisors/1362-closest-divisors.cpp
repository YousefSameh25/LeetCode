class Solution {
public:
    int mn = 1e9 , x , y;
    void div (int num)
    {
        for (int i = 1 ; i * i <= num ; i++)
        {
            if (num % i == 0)
            {
                int d = num / i - i;
                if (mn > d)
                    mn = d, x = i , y = num / i;
            }
        }
    }
    vector<int> closestDivisors(int num) {
        div(num + 1) , div(num + 2);
        return {x,y};
    }
};