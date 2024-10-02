class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector < int > arr2 = arr;
        sort(arr.begin(), arr.end());
        unordered_map < int , int > mp;
        for (auto &it : arr)
        {
            if (!mp.count(it))
                mp[it] = mp.size() + 1;
        }
        vector < int > ans;
        for (int i = 0 ; i < arr.size(); i++)
            arr[i] = mp[arr2[i]];
        return arr;
    }
};