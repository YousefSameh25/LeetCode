class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        bool frq[51];
        memset(frq, 0, sizeof(frq));
        int ans = 0;
        vector < int > ret(A.size());
        for (int i = 0 ; i < A.size(); i++)
        {
            frq[A[i]] ^= 1;
            ans += frq[A[i]] == 0;
            frq[B[i]] ^= 1;
            ans += frq[B[i]] == 0;
            ret[i] = ans;
        }
        return ret;
    }
};