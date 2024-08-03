class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map < int , int > occu;
        for ( int i = 0 ; i < arr.size(); i++)
        {
            occu[arr[i]]++;
            occu[target[i]]--;
        }
        for (auto &it: occu)
        {
            if (it.second)
                return false;
        }
        return true;
    }
};