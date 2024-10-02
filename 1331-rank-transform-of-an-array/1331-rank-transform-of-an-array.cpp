class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector < int > arr2 = arr;
        sort(arr.begin(), arr.end());
        map < int , int > mp;
        for (auto &it : arr)
        {
            if (!mp.count(it))
                mp[it] = mp.size() + 1;
        }
        vector < int > ans;
        for (auto &it : arr2)
            ans.push_back(mp[it]);
        return ans;
    }
};