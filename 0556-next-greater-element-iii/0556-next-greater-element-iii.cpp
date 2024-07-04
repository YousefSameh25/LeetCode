class Solution {
public:
    int nextGreaterElement(int n) {
        string nn = to_string(n);
        bool ok = next_permutation(nn.begin(), nn.end());
        if (!ok or stoll(nn) > INT_MAX)
            return -1;
        return stoll(nn);
    }
};