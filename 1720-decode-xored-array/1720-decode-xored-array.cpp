class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector <int> ret (encoded.size() + 1);
        ret[0] = first;
        for (int i = 1 ; i < ret.size() ; i++)
            ret[i] = encoded[i - 1] ^ ret[i - 1];
        return ret;
    }
};