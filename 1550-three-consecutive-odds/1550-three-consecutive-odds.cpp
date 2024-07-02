class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if (arr.size() < 3)
            return 0;
        for (int i = 1 ; i <= arr.size() - 2; i++)
        {
            if (arr[i - 1] % 2 != 0 and arr[i] % 2 != 0 and arr[i + 1] % 2 != 0)
                return 1;
        }
        return 0;
    }
};