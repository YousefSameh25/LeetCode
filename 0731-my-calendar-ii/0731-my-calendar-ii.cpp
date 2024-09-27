class MyCalendarTwo {
public:
    map <int, int> eventCount;

    MyCalendarTwo() {}

    bool book(int start, int end) {
        eventCount[start]++;
        eventCount[end]--;

        int cnt = 0;
        for (auto &[time, change] : eventCount) {
            cnt += change;
            if (cnt >= 3) {
                eventCount[start]--;
                eventCount[end]++;
                return false;
            }
        }
        return true;
    }
};
