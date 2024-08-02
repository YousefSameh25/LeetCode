class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector < int > v;
        int cntZeros = 0, i = 0;

        while (i < nums.size() and nums[i] == 0)
            i++;

        for (; i < nums.size() ; i++)
        {
            if (nums[i] == 0)
                cntZeros++;
            else
            {
                if (cntZeros)
                    v.push_back(cntZeros);
                cntZeros = 0;
            }
        } 
        if (cntZeros > 0)
        {
            int i = 0;
            while(i < nums.size() and nums[i] == 0)
                cntZeros++, i++;
            v.push_back(cntZeros);
        }
        if (v.size() <= 1)
            return 0;
        sort(v.rbegin(), v.rend());
        int taken = v.size() - 1, ans = 0;
        while(taken--)
        {
            ans += v.back();
            v.pop_back();
        }
        return ans;
    }
    
};