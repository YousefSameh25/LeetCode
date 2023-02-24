class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        multiset < int > mst;
        for (auto &it : nums)
            mst.insert(it);
        while(mst.size())
        {
            int s = *mst.begin();
            for (int i = 0 ; i < k ; i++)
            {
                if (mst.find(s) != mst.end())
                     mst.erase(mst.find(s)) , s++;
                else
                    return false;
            }
        }
        return true;
    }
};

// 1 1 2 2 1 1
// 1 2 3 2 1 0 0 0 1 1 1
// Start + k - 1
