using namespace std;
class Solution {
public:
// 60000
// 9669 + 300
    int maximum69Number (int num) 
    {
        int MOD = 1e5;
        while(MOD >= 10)
        {
            int rem = num % MOD; 
            if (rem < 10)
            {
                if (rem == 6)
                {
                    num += 3;
                    break;
                }
            }
            else if (rem < 100)
            {
                if (rem < 90)
                {
                    num += 30;
                    break;
                }
            }
            else if (rem < 1000)
            {
                if (rem < 900)
                {
                    num += 300;
                    break;
                }
            }
            else 
            {
                if (rem < 9000)
                {
                    num += 3000;
                    break;
                }
            }

            MOD /= 10;
        }
        return num;
    }
};