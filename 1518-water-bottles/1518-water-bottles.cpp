class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int f = numBottles, sum = 0, e = 0;
        while(f)
        {
            sum += f; // Drink
            e += f; // empty
            f = e / numExchange;
            e = e % numExchange;
        }
        return sum;
    }
};