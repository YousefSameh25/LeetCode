class Solution {
public:
    
    vector < vector < int >> ans;
    set < vector < int > > st;
    
    void solve (int kthPos, int sum ,vector< int > &path, vector < int > &nums)
    {
        if (sum == 0)
        {
            ans.push_back(path);
            return;
        }
        if (sum < 0)
            return;

        for (int i = kthPos; i < nums.size(); i++)
        {
            // You are not the first number to be tried at kth position
            // and you equal the prv one.
            // that means a number before you has tried to be at kth position.
            if (i != kthPos and nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            solve(i + 1, sum - nums[i], path, nums);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector < int > path;
        sort(candidates.begin(), candidates.end());
        solve(0, target, path, candidates);
        return ans;
    }
};