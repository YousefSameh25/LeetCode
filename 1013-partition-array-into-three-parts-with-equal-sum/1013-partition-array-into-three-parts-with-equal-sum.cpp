class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) 
    {
        int sum = accumulate (arr.begin() , arr.end() , 0);
        if (sum % 3 != 0)
            return false;
        int ret = 0 , s = 0 ,p = 0;
        for (auto it : arr)
        {
            s += it;
            if (s == sum / 3)
            {
                s = 0;
                p++;
            }
        }
        return p >= 3;
    }
};