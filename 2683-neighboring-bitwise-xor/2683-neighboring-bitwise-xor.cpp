class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int Cxor = 0;
        for (auto &it : derived)
            Cxor ^= it;
        return Cxor == 0;
    }
};