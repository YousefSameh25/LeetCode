class OrderedStream {
public:
    vector < string > mp;
    int expected;
    OrderedStream(int n) {
        mp.assign(n + 1, "");
        expected = 1;
    }
    
    vector<string> insert(int idKey, string value) {
        mp[idKey] = value;
        vector < string > ans;
        while(expected < mp.size() and mp[expected] != "")
            ans.push_back(mp[expected++]);
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */