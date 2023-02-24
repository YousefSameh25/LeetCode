class LUPrefix {
public:
    int v;
    set < int > st;
    LUPrefix(int n) {
        v = n;
        for(int i = 1 ; i <= n ; i++)
            st.insert(i);
    }
    
    void upload(int video) {
        st.erase(video);
    }
    
    int longest() 
    {
        if (st.size() == 0)
            return v;
        auto val = *st.begin();
        return val == 1? 0 : val - 1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */