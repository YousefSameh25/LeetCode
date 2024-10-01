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
        multiset < int > mst;
        for (int i = 0 ; i < arr.size(); i++)
        {
            int need = Add(k - Add(arr[i], k, k), k , k);
            if (mst.find(need) == mst.end())
                mst.insert(Add(arr[i], k, k));
            else
                 mst.erase(mst.find(need));
        }
        return mst.size() == 0;
    }
};