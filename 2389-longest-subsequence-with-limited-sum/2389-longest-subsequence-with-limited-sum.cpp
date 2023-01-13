class Solution {
public:
     vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
     int n = nums.size();
     vector<int>pref(n, 0) , ans; 
        sort(nums.begin() , nums.end());
        int sum = 0;
        for (int i = 0 ; i < n ;i++) {
            sum += nums[i];
            pref[i] = sum;
        }
        for(int i : queries)
        {
            auto iter = upper_bound(pref.begin() , pref.end() , i);
            if ( iter == pref.begin())
                ans.push_back(0);
            else
                ans.push_back(iter - pref.begin());
        }
        return ans;
    }
};