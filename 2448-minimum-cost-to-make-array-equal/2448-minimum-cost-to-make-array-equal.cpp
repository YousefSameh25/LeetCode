class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost)
    {
        
        /*
        1 2  3 5
        2 14 3 1
        
        observation 1: the number with large cost should not move.
        observation 2: the target number will be the number with max cost.
        
        in this case 2
        
        total cost of 1 = 2
        total cost of 3 = 3
        total cost of 5 = 3
        
        total cost = 8.
        
        wrong, why?
        
        Imagine that there are:
        100 elements at index 1 with cost 1
        1 element at index 5 with cost 5
        
        the best answer is moving the element which at index 5!
        
        so lets try brute force on the best target index.
        
        ------------------(T)-----X----Y----Z------
        
        -------------------5------10---13---17-----
        **************************************
        *********************************
        ****************************
        
        17 + 13 + 10 = 40
        
        lets think on how to get th total distance between 5 and other values in O(1).

        
        so if we remove 5 from the result 3 times 
        
        Cost----------------------2-----3----6
        -------------------5------10---13---17-----
                           *******************
                           **************
                           ********
        17 = 0                               
        16 = 6
        15 = 6 + 6
        14 = 6 + 6 + 6
        13 = 6 + 6 + 6 + 6
                                        
                           
        40 - (5 * 3) = 25 step.
        
        but the cost of the steps are not the same. 
        */
  
        unordered_map < int , long long > mp; 
        
        int R = -1;
        for (int i = 0 ; i < nums.size() ; i++)
            mp[nums[i]] += cost[i] , R = max(R , nums[i]);
        
        vector < long long > NumbersLinePre(R + 10 , 0) , NumbersLineSuf(R + 10 , 0);
        
        long long sum = 0 , preCosts = 0;
        for (int i = 0 ; i <= R ; i++)
        {
            NumbersLinePre[i] = sum;
            if (mp.count(i))
                preCosts += mp[i];
            sum += preCosts;
        }
        
        
        sum = 0 , preCosts = 0;
        for (int i = R ; i >= 0 ; i--)
        {
            NumbersLineSuf[i] = sum;
            if (mp.count(i))
                preCosts += mp[i];
            sum += preCosts;
        }
        
        long long ans = 1e18;
        
        for (int i = 0 ; i <= R ; i++)
            ans = min(ans , NumbersLineSuf[i] + NumbersLinePre[i]);
        
        return ans;
        
    }
};