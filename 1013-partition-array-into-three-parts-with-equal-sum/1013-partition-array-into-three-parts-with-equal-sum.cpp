class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) 
    {
        int sum = accumulate (arr.begin() , arr.end() , 0);
        if (sum % 3 != 0)
            return false;
        int s = 0 , p = 0;
        auto i = arr.begin();
        while(i != arr.end() and p < 2)
        {
            s += *i;
            i++;
            if (s == sum / 3)
               p++ , s = 0;
        }
        if(i == arr.end())
            return false;
        p +=  accumulate(i , arr.end() , 0) == sum / 3;
        return p == 3;
    }
};