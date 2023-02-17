class Solution {
public:
    int dp1[1000 + 10][1000 + 10] ,dp2[1000 + 10][1000 + 10];
    
	int LIS(vector<int> &nums, int i, int prev, int previ)
    {
	    if(i < 0)
            return 0;
            
        int &ret = dp1[i][previ];
        
	    if(~ret) 
            return ret;
	    
	     ret = 0;
        
        if (nums[i] < prev)
            ret = LIS(nums , i - 1 , nums[i] , i) + 1;
        
        ret = max (ret , LIS (nums , i - 1 , prev , previ));
        
	    return ret;
	}
	

	int LDS(vector<int> &nums, int i, int prev, int previ)
    {
	    if(i >= nums.size()) 
            return 0;
        
	     int &ret = dp1[i][previ];
        
	    if(~ret) 
            return ret;
	    
	    ret = 0;
        
        if (nums[i] < prev)
            ret = LDS(nums , i + 1 , nums[i], i) + 1;

        ret = max (ret , LDS (nums, i + 1 , prev , previ ));
	    
	    return ret;
	}
    
    int minimumMountainRemovals(vector<int>& nums) 
    {
        memset(dp1 , -1 , sizeof(dp1));
	    memset(dp2 , -1 , sizeof(dp2));
	    int mx = 0;
        
	    for(int i = 0 ; i < nums.size() ; i++)
        { 
            int left = LIS (nums , i - 1 , nums[i] , i);
            int right = LDS (nums , i + 1 , nums[i] , i);
            if (!left or !right)
                continue;
	        mx = max(mx , left + right + 1);
	    }
	    return nums.size() - mx;
    }
};