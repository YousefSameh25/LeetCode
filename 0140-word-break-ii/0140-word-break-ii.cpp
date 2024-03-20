class Solution {
public:
    int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9, p = 31;
    long long pw1[25], pw2[25], pref1[25], pref2[25], inv1[25], inv2[25];
 
    long long add(long long a, long long b, long long m) {
        a %= m, b %= m;
        return (a + b) % m;
    }

    long long mul(long long a, long long b, long long m) {
        a %= m, b %= m;
        return (a * b) % m;
    }

    long long fast_power(long long a, long long b, long long m) {
        if (b == 0 or a == 1)
            return 1;
        long long half = fast_power(a, b / 2, m);
        half = mul(half, half, m);
        if (b & 1)
            half = mul(half, a, m);
        return half;
    }

    void pre() {
        pw1[0] = 1, pw2[0] = 1;
        // p^-1 = p^MOD - 2
        inv1[0] = 1, inv2[0] = 1;
        inv1[1] = fast_power(p, MOD1 - 2, MOD1);
        inv2[1] = fast_power(p, MOD2 - 2, MOD2);
        for (int i = 1; i < 25; i++) {
            pw1[i] = mul(p, pw1[i - 1], MOD1);
            inv1[i] = mul(inv1[1], inv1[i - 1], MOD1);
            pw2[i] = mul(p, pw2[i - 1], MOD2);
            inv2[i] = mul(inv2[1], inv2[i - 1], MOD2);
        }
    }

    pair<int, int> hash_value(string &s) {
        long long ret1 = 0, ret2 = 0;
        for (int i = 0; i < s.size(); i++) {
            ret1 = add(ret1, mul((s[i] - 'a' + 1), pw1[i], MOD1), MOD1);
            pref1[i + 1] = ret1;
            ret2 = add(ret2, mul((s[i] - 'a' + 1), pw2[i], MOD2), MOD2);
            pref2[i + 1] = ret2;
        }
        return make_pair(ret1, ret2);
    }
    
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        pre();
        
        set <pair <int , int>> st;
        
        for (string& str : wordDict)
            st.insert(hash_value(str));

        
        int n = s.size() - 1;
        
        vector <string> ans;
        for (int msk = 0 ; msk < (1 << n) ; msk++)
        {
            string word = "", full = "";
            bool ok = 1;
            for (int i = 0 ; i <= n ; i++)
            {
                word.push_back(s[i]);
                if ((msk >> i) & 1 || i == n) // Add space
                {
                    if (word.size() and st.count(hash_value(word)))
                    {
                        full += word + ((i == n)? "" : " ");
                        word.clear();
                    }
                    else 
                    {
                        ok = 0;
                        break;
                    }
                }
            }
            
            if (ok and full.size())
                ans.push_back(full);
        }
        return ans;
    }
};