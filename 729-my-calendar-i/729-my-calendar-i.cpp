class MyCalendar {
public:
    unordered_map<int, int> u;
    MyCalendar() {
        
    }
    
    bool book(int sNew, int eNew) {
        for(pair<int, int> x : u)
        {
            int sPrev = x.first, ePrev = x.second;
            if(!(sPrev>=eNew || ePrev<=sNew))
                return false;
        }
        u[sNew] = eNew;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */