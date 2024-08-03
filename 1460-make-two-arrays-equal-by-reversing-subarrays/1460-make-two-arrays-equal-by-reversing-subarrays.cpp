class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector < int > occu(1001, 0);
        for ( int i = 0 ; i < arr.size(); i++)
        {
            occu[arr[i]]++;
            occu[target[i]]--;
        }
        for ( int i = 1 ; i <= 1000 ; i++)
        {
            if (occu[i])
                return false;
        }
        return true;
    }
};