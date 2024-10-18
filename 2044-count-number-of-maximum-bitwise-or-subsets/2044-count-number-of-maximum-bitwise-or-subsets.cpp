class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (auto it : nums) maxOr |= it;

        int cnt = 0;
        for (int msk = 0 ;  msk < 1 << nums.size() ; msk++)
        {
            int subOr = 0;
            for (int i = 0 ; i < nums.size(); i++)
            {
                if (msk & (1 << i))
                    subOr |= nums[i];
            }
            cnt += subOr == maxOr;
        }
        return cnt;
    }
};