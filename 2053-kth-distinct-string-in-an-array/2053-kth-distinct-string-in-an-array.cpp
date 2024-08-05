class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map < string , int > frq;
        for (auto &it : arr)
            frq[it]++;

        
        for (auto &it : arr)
        {
            if (frq[it] == 1)
                k--;
            if (!k)
                return it;
        }
        return "";
    }
};