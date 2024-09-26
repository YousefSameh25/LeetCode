class MyCalendar {
public:
    set < pair < int , int > > st;
    MyCalendar() {
        // Nothing.
    }
    
    bool book(int start, int end) 
    {
        end--;
        auto it = st.lower_bound({start, -1});
        if (it != st.end() and (*it).first <= end)
            return false;
        if (it != st.begin() and (*prev(it)).second >= start)
            return false;
        st.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */