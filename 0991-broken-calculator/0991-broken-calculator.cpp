class Solution {
public:  
    
    int brokenCalc(int startValue, int target) {
        /*
            ('/', '+')
            8 -> 5

            8 / 2 = 4
            
            3 -> 2
            
            
        */
        
        int ans = 0;
        while (target > startValue)
        {
            if (target % 2 == 0)
            {
                target >>= 1;
                ans ++;
            } 
            else 
            {
                target ++;
                target >>= 1;
                ans += 2;
            }
        }
        
        return ans + (startValue - target);
    }
};