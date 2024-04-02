class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        vector < vector <int> > ans;
        int n = nums.size();
        int i = 0;
        while(i < n)
        {
            vector <int> tmp;
            int cur = nums[i];
            while(i < n and tmp.size() < 3 and nums[i] - cur <= k)
            {
                tmp.push_back(nums[i]);
                i++;
            }
            if (tmp.size() != 3)
            {
                ans.clear();
                break;
            }
            ans.push_back(tmp);
        }
        
        return ans;
    }
};