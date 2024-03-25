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
  
        vector <pair <int , long long>> Nums;
        
        for (int i = 0 ; i < nums.size() ; i++)
             Nums.emplace_back(nums[i] , cost[i]);
        
        sort(Nums.begin() , Nums.end());
        
        vector < long long > NumbersLinePre(nums.size() + 10 , 0) , NumbersLineSuf(nums.size() + 10 , 0);
        
        long long sum = 0 , preCosts = 0;
        for (int i = 0 ; i < Nums.size() ; i++)
        {
            sum += preCosts * (i != 0? (Nums[i].first - Nums[i - 1].first) : 1);
            
            NumbersLinePre[i] = sum;

            preCosts += Nums[i].second;
        }
        
        
        sum = 0 , preCosts = 0;
        for (int i = Nums.size() - 1 ; i >= 0 ; i--)
        {
            sum += preCosts * (i != Nums.size() - 1? (Nums[i + 1].first - Nums[i].first) : 1);
            
            NumbersLineSuf[i] = sum;
            
            preCosts += Nums[i].second;
        }
        
        long long ans = 1e18;
        
        for (int i = 0 ; i < Nums.size() ; i++)
            ans = min(ans , NumbersLineSuf[i] + NumbersLinePre[i]);
        
        return ans;
        
    }
};