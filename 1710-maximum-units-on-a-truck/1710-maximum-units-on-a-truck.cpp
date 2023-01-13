class Solution {
   public:
    int maximumUnits(vector<vector<int>> & boxTypes, int truckSize) {
        int ret = 0;
        sort(boxTypes.begin() , boxTypes.end(), [&] (auto& a, auto& b) {
            return a[1] > b[1];
        });
        for (auto i : boxTypes)
        {
            ret += min(i[0] , truckSize) * i[1];
            truckSize -= min(truckSize , i[0]);
            if (not truckSize)
                break;
        }
        return ret;
    }
};