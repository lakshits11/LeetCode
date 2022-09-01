class MyCalendarTwo {
public:
    map<int, int> u;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        u[start]++;
        u[end]--;
        int sum = 0;
        for(auto &x : u)
        {
            sum += x.second;
            if(sum >= 3)
            {
                u[start]--;
                u[end]++;
                return false;
            }
        }
        return true;
    }
};