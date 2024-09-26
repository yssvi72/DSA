class MyCalendar {
public:
    map<int, int> calendar; // stores intervals as (start, end)
    
    MyCalendar() {}
    
    bool book(int start, int end) {
        // Find the first event that ends after 'start'
        auto nextEvent = calendar.lower_bound(start);
        
        // Check if the next event overlaps with the current booking
        if (nextEvent != calendar.end() && nextEvent->first < end) {
            return false; // The next event starts before this one ends
        }

        // Check if the previous event overlaps with the current booking
        if (nextEvent != calendar.begin()) {
            auto prevEvent = prev(nextEvent);
            if (prevEvent->second > start) {
                return false; // The previous event ends after this one starts
            }
        }
        
        // If no overlap, add the event to the calendar
        calendar[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
