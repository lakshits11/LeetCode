class MyCalendarThree {
public:
    map<int, int> m;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        
        int sum = 0, maxi = -1;
        for(auto &x : m)
        {
            sum += x.second;
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */