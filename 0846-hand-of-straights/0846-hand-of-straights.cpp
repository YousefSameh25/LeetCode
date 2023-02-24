class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        multiset < int > mst;
        for (auto &it : hand)
            mst.insert(it);
        while(mst.size())
        {
            int s = *mst.begin();
            for (int i = 0 ; i < groupSize ; i++)
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