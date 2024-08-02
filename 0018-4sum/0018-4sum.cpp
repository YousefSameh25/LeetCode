class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        set < vector < int > > st;
        vector < vector < int > > ans;
        for (int i = 0 ; i + 3 < nums.size(); i++)
        {
            for (int j = i + 1; j + 2 < nums.size(); j++)
            {
                int k = j + 1, z = nums.size() - 1;
                while(k < z)
                {
                    if (1LL * nums[i] + nums[j] + nums[k] + nums[z] > target)
                        z--;
                    else if (1LL * nums[i] + nums[j] + nums[k] + nums[z] < target)
                        k++;
                    else
                    {
                        vector < int > temp = {nums[i], nums[j], nums[k], nums[z]};
                        sort(temp.begin(), temp.end());
                        if (!st.count(temp))
                        {
                            ans.push_back(temp);
                            st.insert(temp);
                        }
                        k++, z--;
                    }
                }
            }
        }
        return ans;
    }
};