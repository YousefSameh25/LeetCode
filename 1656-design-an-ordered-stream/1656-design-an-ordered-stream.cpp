class OrderedStream {
public:
    map < int, string > mp;
    int expected = 1;
    OrderedStream(int n) {
        
    }
    
    vector<string> insert(int idKey, string value) {
        mp[idKey] = value;
        vector < string > ans;
        while(mp.count(expected))
            ans.push_back(mp[expected++]);
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */