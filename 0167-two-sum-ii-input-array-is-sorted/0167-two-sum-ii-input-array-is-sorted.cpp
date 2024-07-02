class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector < int > idx (2010, -1);
        for (int i = 0 ; i < numbers.size(); i++)
        {
            int rem = target - numbers[i];
            if (rem < -1000 or rem > 1000)
                continue;
            if (idx[rem + 1000] != -1)
                return {idx[rem + 1000] + 1, i + 1};
            idx[numbers[i] + 1000] = i;
        }
        return {};
    }
};