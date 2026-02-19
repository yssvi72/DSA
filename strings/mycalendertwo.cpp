class MyCalendarTwo {
public:
    multiset<int> starts1, ends1, starts2, ends2;
    MyCalendarTwo() {}

    bool book(int start, int end) {
        if (starts2.size() > 0) {
            auto itEnd = ends2.upper_bound(start);
            if (itEnd != ends2.end()) {
                int dis = distance(ends2.begin(), itEnd);
                auto itStart = next(starts2.begin(), dis);
                if (*itStart < end) {
                    return false;
                }
            }
        }
        if (starts1.size() > 0) {
            auto itEnd = ends1.upper_bound(start);
            while (itEnd != ends1.end()) {
                int dis = distance(ends1.begin(), itEnd);
                auto itStart = next(starts1.begin(), dis);
                if (*itStart < end) {
                    int tmpStart = max(*itStart, start);
                    int tmpEnd = min(*itEnd, end);
                    starts2.insert(tmpStart);
                    ends2.insert(tmpEnd);
                } else {
                    break;
                }
                itEnd++;
            }
        }
        starts1.insert(start);
        ends1.insert(end);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
