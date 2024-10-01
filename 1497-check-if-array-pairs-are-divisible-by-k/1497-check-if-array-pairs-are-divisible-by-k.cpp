class Solution {
public:
    int Add(int x, int y, int k)
    {
        x %= k;
        y %= k;
        int temp = x + y;
        temp %= k;
        return (temp + k) % k;
    }
    bool canArrange(vector<int>& arr, int k) {
        unordered_map < int, int > mp;
        for (int i = 0 ; i < arr.size(); i++)
        {
            int need = Add(k - Add(arr[i], k, k), k , k);
            if (!mp.count(need) or mp[need] == 0)
                mp[Add(arr[i], k, k)]++;
            else
                mp[need]--;
        }
        int sum = 0;
        for (auto &it : mp) sum += it.second;
        return sum == 0;
    }
};