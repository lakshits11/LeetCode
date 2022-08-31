class MyCalendar {
public:
    set<pair<int, int>> s;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto slot = s.lower_bound({start, end});
        if(slot != s.end() && (slot->first < end) || (slot != s.begin()) && (prev(slot)->second > start))
            return false;
        s.insert({start, end});
        return true;
    }

};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */