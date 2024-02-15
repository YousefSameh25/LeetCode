class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map <int , int> last;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            if (!last.count(nums[i]))
                last[nums[i]] = i;
            else
            {
                int diff = i - last[nums[i]];
                if (diff <= k)
                    return true;
                last[nums[i]] = i;
            }
        }
        return false;
    }
};