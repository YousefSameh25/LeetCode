class Solution {
public:
    bool reorderedPowerOf2(int n) {
        set <multiset<int>> st;
        int p = 0;
        while(p < 32)
        {
            int num = (1 << p);
            multiset <int> mst;
            while(num)
            {
                mst.insert(num % 10);
                num /= 10;
            }
            st.insert(mst);
            p++;
        }
        
        multiset <int> mst;
        while(n)
        {
            mst.insert(n % 10);
            n /= 10;
        }
        
        return st.count(mst);
    }
};