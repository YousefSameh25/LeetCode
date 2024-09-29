class AllOne {
public:
    unordered_map < string , int > mp;
    set < pair < int , string >> st;
    AllOne() {
    }
    
    void inc(string key) {
        st.erase({mp[key], key});
        mp[key]++;
        st.insert({mp[key], key});
    }
    
    void dec(string key) {
        string s = key;
        int f = mp[key];

        st.erase({f, s});
        f--;
        if (f)
        {
            st.insert({f, s});
            mp[s] = f;
        }
        else
            mp.erase(s);
    }
    
    string getMaxKey() {
        if (!st.size())
            return "";
        return (*st.rbegin()).second;
    }
    
    string getMinKey() {
        if (!st.size())
            return "";
        return (*st.begin()).second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */