class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map < int , bool > mp;
        for (auto it: arr)
        {
            if (it % 2 == 0 and mp.count(it / 2))
                return 1;
            if (mp.count(it * 2))
                return 1;
            mp[it] = 1;
        }
        return 0;
    }
};